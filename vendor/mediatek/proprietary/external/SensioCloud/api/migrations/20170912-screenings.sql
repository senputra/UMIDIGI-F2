CREATE TABLE hc.screenings (
    screeningid serial PRIMARY KEY,
    measurementid integer NOT NULL,
    profileid integer NOT NULL,
    userid character varying(12) NOT NULL,
    confidencelevel smallint NOT NULL,
    risklevel smallint NOT NULL,
    riskprobability smallint NOT NULL,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL,
);

