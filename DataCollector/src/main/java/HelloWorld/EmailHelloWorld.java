package HelloWorld;

import java.io.IOException;
import java.util.Properties;
import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

import java.io.InputStream;
import java.io.ByteArrayInputStream;
import java.io.UnsupportedEncodingException;
import javax.activation.DataHandler;
import javax.mail.Multipart;
import javax.mail.internet.MimeBodyPart;
import javax.mail.internet.MimeMultipart;


import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Copyright 2016 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

public class EmailHelloWorld
{
	@SuppressWarnings("serial")
	private static class MailServlet{

		public void doPost(String type) throws IOException {
			if (type != null && type.equals("multipart")) {
				sendMultipartMail();
			} else {
				sendSimpleMail();
			}
		}

		private void sendSimpleMail() {
			// [START simple_example]
			Properties props = new Properties();
			Session session = Session.getDefaultInstance(props, null);

			try {
				Message msg = new MimeMessage(session);
				msg.setFrom(new InternetAddress("admin@example.com", "Example.com Admin"));
				msg.addRecipient(Message.RecipientType.TO,
						new InternetAddress("user@example.com", "Mr. User"));
				msg.setSubject("Your Example.com account has been activated");
				Transport.send(msg);
			} catch (AddressException e) {
				// ...
			} catch (MessagingException e) {
				// ...
			} catch (UnsupportedEncodingException e) {
				// ...
			}
			// [END simple_example]
		}

		private void sendMultipartMail() {
			Properties props = new Properties();
			Session session = Session.getDefaultInstance(props, null);

			String msgBody = "...";

			try {
				Message msg = new MimeMessage(session);
				msg.setFrom(new InternetAddress("admin@example.com", "Example.com Admin"));
				msg.addRecipient(Message.RecipientType.TO,
						new InternetAddress("user@example.com", "Mr. User"));
				msg.setSubject("Your Example.com account has been activated");
				msg.setText(msgBody);

				// [START multipart_example]
				String htmlBody = "";          // ...
				byte[] attachmentData = null;  // ...
				Multipart mp = new MimeMultipart();

				MimeBodyPart htmlPart = new MimeBodyPart();
				htmlPart.setContent(htmlBody, "text/html");
				mp.addBodyPart(htmlPart);

				MimeBodyPart attachment = new MimeBodyPart();
				InputStream attachmentDataStream = new ByteArrayInputStream(attachmentData);
				attachment.setFileName("manual.pdf");
				attachment.setContent(attachmentDataStream, "application/pdf");
				mp.addBodyPart(attachment);

				msg.setContent(mp);
				// [END multipart_example]

				Transport.send(msg);

			} catch (AddressException e) {
				// ...
			} catch (MessagingException e) {
				// ...
			} catch (UnsupportedEncodingException e) {
				// ...
			}
		}
	}

	public static void main(String [] args)
	{
		MailServlet lMailServlet = new MailServlet();
		try
		{
			lMailServlet.doPost( "multipart" );
		}
		catch( IOException e )
		{
			e.printStackTrace();
		}
	}
}



