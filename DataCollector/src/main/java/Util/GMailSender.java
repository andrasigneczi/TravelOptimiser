package Util;

import Configuration.Configuration;
import Storage.EmailNotifierAgent;
import org.apache.log4j.Logger;

import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import java.io.UnsupportedEncodingException;
import java.lang.*;
import java.util.Properties;

/**
 * Created by Andras on 12/04/2017.
 */
public class GMailSender
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( GMailSender.class);

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
				new javax.mail.Authenticator() {
					protected PasswordAuthentication getPasswordAuthentication() {
						return new PasswordAuthentication( smtp_username, smtp_password );
					}
				});

		try {

			Message msg = new MimeMessage( session );
			msg.setFrom( new InternetAddress( fromAddress, fromName ));
			msg.addRecipient( Message.RecipientType.TO,
					new InternetAddress( toAddress, toName ));
			msg.setSubject( subject );

			msg.setText( msgBody );
			//Transport.send(msg);
			Transport transport = session.getTransport( "smtps" );
			transport.connect( smtp_host, Integer.parseInt( smtp_port ), smtp_username, smtp_password );
			transport.sendMessage( msg, msg.getAllRecipients());
			transport.close();
		} catch (MessagingException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		} catch (UnsupportedEncodingException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		}
	}
}
