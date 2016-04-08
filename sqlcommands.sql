BUD-CRL Mon, 11 Jul 6:10-8:15

SOF-HHN Sat, 06 Aug Tue, 09 Aug

HHN-SOF Tue, 05 Jul

// one way data
SELECT 
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM 
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT 
WHERE 
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-07-05 %' 
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='SOF'
		AND TDR.AirportCode_GoingTo='HHN'
		AND TDR_PT.OutboundTrip='false'
	) OR (
		TDR.AirportCode_LeavingFrom='HHN'
		AND TDR.AirportCode_GoingTo='SOF'
		AND TDR_PT.OutboundTrip='true'
	))
ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;


SELECT 
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM 
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT 
WHERE 
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-07-11 06:10'
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='BUD'
		AND TDR.AirportCode_GoingTo='CRL'
		AND TDR_PT.OutboundTrip='true'
	) OR (
		TDR.AirportCode_LeavingFrom='CRL'
		AND TDR.AirportCode_GoingTo='BUD'
		AND TDR_PT.OutboundTrip='false'
	))
ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;

SELECT 
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM 
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT 
WHERE 
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-08-06 %' 
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='SOF'
		AND TDR.AirportCode_GoingTo='HHN'
		AND TDR_PT.OutboundTrip='true'
	) OR (
		TDR.AirportCode_LeavingFrom='HHN'
		AND TDR.AirportCode_GoingTo='SOF'
		AND TDR_PT.OutboundTrip='false'
	))
ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;

SELECT 
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM 
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT 
WHERE 
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-08-09 %' 
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='HHN'
		AND TDR.AirportCode_GoingTo='SOF'
		AND TDR_PT.OutboundTrip='true'
	) OR (
		TDR.AirportCode_LeavingFrom='SOF'
		AND TDR.AirportCode_GoingTo='HHN'
		AND TDR_PT.OutboundTrip='false'
	))
ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;

// ******************************
// return ticket data
// ******************************
SELECT
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT
WHERE
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-08-06 %'
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='HHN'
		AND TDR.AirportCode_GoingTo='SOF'
		AND TDR_PT.OutboundTrip='false'
	) OR (
		TDR.AirportCode_LeavingFrom='SOF'
		AND TDR.AirportCode_GoingTo='HHN'
		AND TDR_PT.OutboundTrip='true'
	))
UNION
SELECT
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT
WHERE
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-08-09 %'
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='HHN'
		AND TDR.AirportCode_GoingTo='SOF'
		AND TDR_PT.OutboundTrip='true'
	) OR (
		TDR.AirportCode_LeavingFrom='SOF'
		AND TDR.AirportCode_GoingTo='HHN'
		AND TDR_PT.OutboundTrip='false'
	))
ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;

SELECT
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT
WHERE
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-07-08 20:45'
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='BUD'
		AND TDR.AirportCode_GoingTo='CRL'
		AND TDR_PT.OutboundTrip='false'
	) OR (
		TDR.AirportCode_LeavingFrom='CRL'
		AND TDR.AirportCode_GoingTo='BUD'
		AND TDR_PT.OutboundTrip='true'
	))
UNION
SELECT
    Airline,
    AirportCode_LeavingFrom,
    AirportCode_GoingTo,
    OutboundTrip,
	DepartureDatetime,
	ArrivalDatetime,
	Prices_BasicFare_Discount,
	SearchDatetime,
	Search_ID
FROM
	TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT
WHERE
	TDR.ID=TDR_PT.TravelDataResult_ID
	AND TDR_PT.DepartureDatetime like '2016-07-11 06:10'
	AND TDR.Airline = 'wizzair'
	AND ((
		TDR.AirportCode_LeavingFrom='BUD'
		AND TDR.AirportCode_GoingTo='CRL'
		AND TDR_PT.OutboundTrip='true'
	) OR (
		TDR.AirportCode_LeavingFrom='CRL'
		AND TDR.AirportCode_GoingTo='BUD'
		AND TDR_PT.OutboundTrip='false'
	))

ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;
