package PageGuest;

import java.io.IOException;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Created by Andras on 16/06/2017.
 */
public class AccomodationData_RESULT implements Cloneable, Serializable
{
	public char    mType = 'A';
	public String  mName = "";
	public char    mSite = 'B';
	public String  mURL  = "";
	public String  mCheckInPolicy = "";
	public String  mCheckOutPolicy = "";
	public Double  mScore = 0.;
	public String  mAddress = "";


	public static class Room implements Cloneable, Serializable
	{
		public String  mName = "";
		public Double  mPrice = 0.;
		public String  mMaxOccupancy = "";
		public boolean mBreakfastIncluded = false;
		public String  mRoomSize = "";
		public String  mRoomHook = "";
		public String  mCancellationPolicy = "";

		@Override
		public Object clone() throws CloneNotSupportedException
		{
			return super.clone();
		}

		private void writeObject(java.io.ObjectOutputStream out) throws IOException
		{
			out.writeObject( mName );
			out.writeObject( mPrice );
			out.writeObject( mMaxOccupancy );
			out.writeObject( mBreakfastIncluded );
			out.writeObject( mRoomSize );
			out.writeObject( mRoomHook );
			out.writeObject( mCancellationPolicy );
		}

		private void readObject(java.io.ObjectInputStream in) throws IOException, ClassNotFoundException
		{
			mName               = (String)in.readObject();
			mPrice              = (Double)in.readObject();
			mMaxOccupancy       = (String)in.readObject();
			mBreakfastIncluded  = (boolean)in.readObject();
			mRoomSize           = (String)in.readObject();
			mRoomHook           = (String)in.readObject();
			mCancellationPolicy = (String)in.readObject();
		}
	}

	public AccomodationData_INPUT mAccomodationData_INPUT = null;
	public ArrayList<Room> mAvailableRooms = new ArrayList<>(  );
	public String mRecordedDatetime = LocalDateTime.now().format( DateTimeFormatter.ofPattern( "yyyy-MM-dd HH:mm:ss" ));

	@Override
	public Object clone() throws CloneNotSupportedException
	{
		AccomodationData_RESULT ret = (AccomodationData_RESULT)super.clone();
		ret.mAvailableRooms = (ArrayList<Room>)mAvailableRooms.clone();
		return ret;
	}

	private void writeObject(java.io.ObjectOutputStream out) throws IOException
	{
		out.writeObject( mType );
		out.writeObject( mName );
		out.writeObject( mSite );
		out.writeObject( mURL );
		out.writeObject( mCheckInPolicy );
		out.writeObject( mCheckOutPolicy );
		out.writeObject( mScore );
		out.writeObject( mAddress );
		out.writeObject( mAccomodationData_INPUT );
		out.writeObject( mRecordedDatetime );
		out.writeObject( mAvailableRooms );
		//for( Room result : mAvailableRooms )
		//	out.writeObject( result );
	}

	private void readObject(java.io.ObjectInputStream in) throws IOException, ClassNotFoundException
	{
		mType = (char)in.readObject();
		mName = (String)in.readObject();
		mSite = (char)in.readObject();
		mURL = (String)in.readObject();
		mCheckInPolicy = (String)in.readObject();
		mCheckOutPolicy = (String)in.readObject();
		mScore = (Double)in.readObject();
		mAddress = (String)in.readObject();
		mAccomodationData_INPUT = (AccomodationData_INPUT) in.readObject();
		mRecordedDatetime = (String)in.readObject();
		mAvailableRooms = (ArrayList<Room>)in.readObject();
		//mAvailableRooms = new ArrayList<>();
//		int lSize = in.readInt();
//		for( int i = 0; i < lSize; ++i )
//			mAvailableRooms.add((Room)in.readObject());
	}
}
