CREATE TABLE IF NOT EXISTS hc.firmwares (
  id serial primary key,
  majorversion smallint not null,
  minorversion smallint not null default 0,
  createdat timestamp without time zone DEFAULT now() NOT NULL,
  createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
  updatedat timestamp without time zone DEFAULT now() NOT NULL,
  updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
  status boolean DEFAULT true NOT NULL
);

CREATE TABLE IF NOT EXISTS hc.firmwarefiles (
  id serial primary key,
  firmwareid integer not null,
  filename text not null,
  filepath text not null,
  createdat timestamp without time zone DEFAULT now() NOT NULL,
  createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
  updatedat timestamp without time zone DEFAULT now() NOT NULL,
  updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
  status boolean DEFAULT true NOT NULL
);

CREATE TABLE IF NOT EXISTS hc.firmwaredata (
  id serial primary key,
  firmwarefileid integer unique not null,
  data bytea not null,
  createdat timestamp without time zone DEFAULT now() NOT NULL,
  createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
  updatedat timestamp without time zone DEFAULT now() NOT NULL,
  updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
  status boolean DEFAULT true NOT NULL
);
