package Util;

import Configuration.Configuration;
import Storage.EmailNotifierAgent;
import org.apache.log4j.Logger;

import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import java.io.UnsupportedEncodingException;
import java.lang.*;
import java.util.Comparator;
import java.util.Properties;
import java.util.TreeSet;

/**
 * Created by Andras on 12/04/2017.
 */
public class GMailSender
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( GMailSender.class );
	public class Email {
		public String mFromAddress;
		public String mFromName;
		public String mToAddress;
		public String mToName;
		public String mSubject;
		public String mMsgBody;
		public String mDepartureDatetime;

		public Email( String fromAddress, String fromName, String toAddress, String toName,
		       String subject, String msgBody, String departureDatetime )
		{
			mFromAddress = fromAddress;
			mFromName    = fromName;
			mToAddress   = toAddress;
			mToName      = toName;
			mSubject     = subject;
			mMsgBody     = msgBody;
			mDepartureDatetime = departureDatetime;
		}
	}

	public static class EmailComparator implements Comparator<Email>
	{
		public int compare( Email s1, Email s2 ) {
			int r = s1.mDepartureDatetime.compareTo( s2.mDepartureDatetime );
			if( r != 0 ) return r;
			r = s1.mFromAddress.compareTo( s2.mFromAddress );
			if( r != 0 ) return r;
			r = s1.mToAddress.compareTo( s2.mToAddress );
			if( r != 0 ) return r;
			return s1.mSubject.compareTo( s2.mSubject );
		}
	}

	public static class EmailComparatorV2 implements Comparator<Email>
	{
		public int compare( Email s1, Email s2 ) {
			int r = s1.mFromAddress.compareTo( s2.mFromAddress );
			if( r != 0 ) return r;
			r = s1.mToAddress.compareTo( s2.mToAddress );
			if( r != 0 ) return r;
			return s1.mSubject.compareTo( s2.mSubject );
		}
	}

	private static TreeSet<Email> mEmails = new TreeSet<Email>( new EmailComparator() );

	public static void send( String fromAddress, String fromName,
	                         String toAddress, String toName,
	                         String subject, String msgBody )
	{
		Configuration lConfiguration = Configuration.getInstance();
		String smtp_host = "smtp.gmail.com";
		String smtp_port = "465";
		String smtp_username = lConfiguration.getValue( "/configuration/global/SmtpUserName", "" );
		String smtp_password = lConfiguration.getValue( "/configuration/global/SmtpPassword", "" );

		Properties props = new Properties();
		props.put( "mail.smtp.host", smtp_host );
		props.put( "mail.smtp.socketFactory.port", smtp_port );
		props.put( "mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory" );
		props.put( "mail.smtp.auth", "true" );
		props.put( "mail.smtp.port", "465" );
		props.put( "mail.smtp.starttls.enable", "true" );

		Session session = Session.getDefaultInstance( props,
				new javax.mail.Authenticator()
				{
					protected PasswordAuthentication getPasswordAuthentication()
					{
						return new PasswordAuthentication( smtp_username, smtp_password );
					}
				}
		);

		try
		{

			Message msg = new MimeMessage( session );
			msg.setFrom( new InternetAddress( fromAddress, fromName ) );
			msg.addRecipient( Message.RecipientType.TO,
					new InternetAddress( toAddress, toName )
			);
			msg.setSubject( subject );

			msg.setText( msgBody );
			//Transport.send(msg);
			Transport transport = session.getTransport( "smtps" );
			transport.connect( smtp_host, Integer.parseInt( smtp_port ), smtp_username, smtp_password );
			transport.sendMessage( msg, msg.getAllRecipients() );
			transport.close();
		}
		catch( MessagingException e )
		{
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		}
		catch( UnsupportedEncodingException e )
		{
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		}
	}

	public void add( String fromAddress, String fromName, String toAddress, String toName,
					 String subject, String msgBody, String departureDatetime )
	{
		Email emailToFind = new Email( fromAddress, fromName, toAddress, toName, subject, msgBody, departureDatetime );
		if( mEmails.contains( emailToFind ))
		{
			Email original = mEmails.floor( emailToFind );
			original.mMsgBody += "\n" + msgBody;
		}
		else
		{
			mEmails.add( emailToFind );
		}
	}

	private void mergeEmails()
	{
		TreeSet<Email> mergedEmails = new TreeSet<Email>( new EmailComparatorV2() );
		for( Email emailToFind : mEmails )
		{
			if( mergedEmails.contains( emailToFind ))
			{
				Email original = mergedEmails.floor( emailToFind );
				original.mMsgBody += "\n" + emailToFind.mMsgBody;
			}
			else
			{
				mergedEmails.add( emailToFind );
			}
		}
		mEmails.clear();
		for( Email email : mergedEmails )
		{
			mEmails.add(email);
		}
	}

	public void sendAll()
	{
		mergeEmails();
		for( Email email : mEmails )
		{
			send( email.mFromAddress, email.mFromName, email.mToAddress, email.mToName, email.mSubject, email.mMsgBody );
		}
		mEmails.clear();
	}
}