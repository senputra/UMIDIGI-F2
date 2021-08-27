--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.5
-- Dumped by pg_dump version 9.6.6

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: hc; Type: SCHEMA; Schema: -; Owner: -
--

  CREATE SCHEMA hc;


--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: -
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


--
-- Name: pgcrypto; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS pgcrypto WITH SCHEMA public;


--
-- Name: EXTENSION pgcrypto; Type: COMMENT; Schema: -; Owner: -
--

COMMENT ON EXTENSION pgcrypto IS 'cryptographic functions';


SET search_path = public, pg_catalog;

--
-- Name: drugtype; Type: TYPE; Schema: public; Owner: -
--

CREATE TYPE drugtype AS ENUM (
    'none',
    'hypertension',
    'hypotension'
);


--
-- Name: gender; Type: TYPE; Schema: public; Owner: -
--

CREATE TYPE gender AS ENUM (
    'male',
    'female',
    'other'
);


--
-- Name: weightunit; Type: TYPE; Schema: public; Owner: -
--

CREATE TYPE weightunit AS ENUM (
    'kg',
    'jin',
    'lb'
);


--
-- Name: charactorize(bigint, integer); Type: FUNCTION; Schema: public; Owner: -
--

CREATE FUNCTION charactorize(value bigint, maxlength integer DEFAULT 11) RETURNS text
    LANGUAGE plpgsql
    AS $$
DECLARE
  chars text[] :=
  '{z,A,9,V,y,x,w,0,u,B,C,7,D,t,s,r,f,q,F,G,H,I,6,p,J,o,n,m,K,5,L,3,k,j,i,4,h,M,N,g,O,P,Q,R,l,S,T,E,e,d,U,c,8,2,W,X,b,Y,1,v,Z,a}';
  result TEXT := '';
BEGIN
  IF maxLength = 1 THEN
    return chars[(modular(value , array_length(chars, 1)) + 1)];
  END IF;
  IF value >= 0::BIGINT THEN
    IF value >= 62 THEN
      return charactorize(value /array_length(chars, 1), maxLength - 1) || chars[ modular(value, array_length(chars, 1)) + 1];
    ELSE
      FOR i IN 1..(maxLength -1) LOOP
        result := chars[1] || result;
      END LOOP;
      return result || chars[(modular(value, array_length(chars, 1)) + 1)];
    END IF;
  ELSE
    IF value > (0 - array_length(chars, 1))::BIGINT THEN
      FOR i IN 1..(maxLength -1) LOOP
        result := chars[62] || result;
      END LOOP;
      return result || chars[(modular(value, array_length(chars, 1))  + 1)];
    ELSE
      return charactorize(value /array_length(chars, 1), maxLength - 1) || chars[ modular(value, array_length(chars, 1)) + 1];
    END IF;
  END IF;
END;
$$;


--
-- Name: feistelcipherbigint(bigint, bigint, bigint, bigint); Type: FUNCTION; Schema: public; Owner: -
--

CREATE FUNCTION feistelcipherbigint(value bigint, randomseed bigint, randomsalt bigint, randombase bigint) RETURNS bigint
    LANGUAGE plpgsql IMMUTABLE STRICT
    AS $$
DECLARE
 l1 BIGINT;
 l2 BIGINT;
 r1 BIGINT;
 r2 BIGINT;
 i BIGINT:=0;
BEGIN
  l1:= (value >> 32) & 4294967295;
  r1:= value&4294967295;
  WHILE i<3 LOOP
    l2:=r1;
    r2:=l1 # ((((randomSeed*r1+randomSalt)%randomBase)/randomBase::FLOAT)*2147483647)::BIGINT;
    l1:=l2;
    r1:=r2;
    i:=i+1;
  END LOOP;
  return ((l1::BIGINT<<32) + r1);
END;
$$;


--
-- Name: modular(bigint, integer); Type: FUNCTION; Schema: public; Owner: -
--

CREATE FUNCTION modular(value bigint, dividend integer) RETURNS integer
    LANGUAGE plpgsql
    AS $$
BEGIN
  IF value < 0 THEN
    value := value - 1;
    IF (value % dividend) = 0 THEN
      return value % dividend;
    ELSE
      return value % dividend + dividend;
    END IF;
  ELSE
    return value % dividend;
  END IF;
END;
$$;


--
-- Name: update_updatedat_column(); Type: FUNCTION; Schema: public; Owner: -
--

CREATE FUNCTION update_updatedat_column() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
  NEW.updatedat = now();
  RETURN NEW;
END;
$$;


SET search_path = hc, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: calibrations; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE calibrations (
    calibrationid integer NOT NULL,
    profileid integer NOT NULL,
    userid character varying(12) NOT NULL,
    data numeric(10,2)[],
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: calibrations_calibrationid_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE calibrations_calibrationid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: calibrations_calibrationid_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE calibrations_calibrationid_seq OWNED BY calibrations.calibrationid;


--
-- Name: firmwaredata; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE firmwaredata (
    id integer NOT NULL,
    firmwarefileid integer NOT NULL,
    data bytea NOT NULL,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: firmwaredata_id_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE firmwaredata_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: firmwaredata_id_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE firmwaredata_id_seq OWNED BY firmwaredata.id;


--
-- Name: firmwarefiles; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE firmwarefiles (
    id integer NOT NULL,
    firmwareid integer NOT NULL,
    filename text NOT NULL,
    filepath text NOT NULL,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: firmwarefiles_id_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE firmwarefiles_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: firmwarefiles_id_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE firmwarefiles_id_seq OWNED BY firmwarefiles.id;


--
-- Name: firmwares; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE firmwares (
    id integer NOT NULL,
    majorversion smallint NOT NULL,
    minorversion smallint DEFAULT 0 NOT NULL,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: firmwares_id_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE firmwares_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: firmwares_id_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE firmwares_id_seq OWNED BY firmwares.id;


--
-- Name: measurements_measurementid_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE measurements_measurementid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: measurements; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE measurements (
    measurementid integer DEFAULT nextval('measurements_measurementid_seq'::regclass) NOT NULL,
    profileid integer NOT NULL,
    userid character varying(12) NOT NULL,
    profiledataid integer,
    "timestamp" timestamp without time zone NOT NULL,
    systolic smallint NOT NULL,
    diastolic smallint NOT NULL,
    spo2 smallint NOT NULL,
    heartrate smallint NOT NULL,
    fatigue smallint NOT NULL,
    pressure smallint NOT NULL,
    data text,
    gzdata bytea,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: profiledata; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE profiledata (
    profiledataid integer NOT NULL,
    profileid integer NOT NULL,
    gender public.gender NOT NULL,
    birthday date NOT NULL,
    height smallint NOT NULL,
    weight smallint NOT NULL,
    weightunit public.weightunit DEFAULT 'kg'::public.weightunit NOT NULL,
    drug public.drugtype DEFAULT 'none'::public.drugtype NOT NULL,
    drugtime smallint,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: profiledata_profiledataid_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE profiledata_profiledataid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: profiledata_profiledataid_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE profiledata_profiledataid_seq OWNED BY profiledata.profiledataid;


--
-- Name: profiles; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE profiles (
    profileid integer NOT NULL,
    userid character varying(12) NOT NULL,
    name character varying(100),
    uniqueid character varying(100),
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: profiles_profileid_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE profiles_profileid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: profiles_profileid_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE profiles_profileid_seq OWNED BY profiles.profileid;


--
-- Name: screenings; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE screenings (
    screeningid integer NOT NULL,
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
    status boolean DEFAULT true NOT NULL
);


--
-- Name: screenings_screeningid_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE screenings_screeningid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: screenings_screeningid_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE screenings_screeningid_seq OWNED BY screenings.screeningid;


--
-- Name: users; Type: TABLE; Schema: hc; Owner: -
--

CREATE TABLE users (
    useridseq bigint NOT NULL,
    userid character varying(12) NOT NULL,
    username character varying(50),
    serialid character varying(30),
    birthday date,
    phone character varying(15),
    email character varying(100),
    isprivilegeduser boolean DEFAULT false NOT NULL,
    authid character varying(100) NOT NULL,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    status boolean DEFAULT true NOT NULL
);


--
-- Name: users_useridseq_seq; Type: SEQUENCE; Schema: hc; Owner: -
--

CREATE SEQUENCE users_useridseq_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: users_useridseq_seq; Type: SEQUENCE OWNED BY; Schema: hc; Owner: -
--

ALTER SEQUENCE users_useridseq_seq OWNED BY users.useridseq;


--
-- Name: calibrations calibrationid; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY calibrations ALTER COLUMN calibrationid SET DEFAULT nextval('calibrations_calibrationid_seq'::regclass);


--
-- Name: firmwaredata id; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwaredata ALTER COLUMN id SET DEFAULT nextval('firmwaredata_id_seq'::regclass);


--
-- Name: firmwarefiles id; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwarefiles ALTER COLUMN id SET DEFAULT nextval('firmwarefiles_id_seq'::regclass);


--
-- Name: firmwares id; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwares ALTER COLUMN id SET DEFAULT nextval('firmwares_id_seq'::regclass);


--
-- Name: profiledata profiledataid; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY profiledata ALTER COLUMN profiledataid SET DEFAULT nextval('profiledata_profiledataid_seq'::regclass);


--
-- Name: profiles profileid; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY profiles ALTER COLUMN profileid SET DEFAULT nextval('profiles_profileid_seq'::regclass);


--
-- Name: screenings screeningid; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY screenings ALTER COLUMN screeningid SET DEFAULT nextval('screenings_screeningid_seq'::regclass);


--
-- Name: users useridseq; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY users ALTER COLUMN useridseq SET DEFAULT nextval('users_useridseq_seq'::regclass);


--
-- Name: users userid; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY users ALTER COLUMN userid SET DEFAULT ('U'::text || public.charactorize(public.feistelcipherbigint(currval('users_useridseq_seq'::regclass), (89336549)::bigint, '9137831701'::bigint, '84189318179'::bigint)));


--
-- Name: calibrations calibrations_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY calibrations
    ADD CONSTRAINT calibrations_pkey PRIMARY KEY (calibrationid);


--
-- Name: firmwaredata firmwaredata_firmwarefileid_key; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwaredata
    ADD CONSTRAINT firmwaredata_firmwarefileid_key UNIQUE (firmwarefileid);


--
-- Name: firmwaredata firmwaredata_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwaredata
    ADD CONSTRAINT firmwaredata_pkey PRIMARY KEY (id);


--
-- Name: firmwarefiles firmwarefiles_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwarefiles
    ADD CONSTRAINT firmwarefiles_pkey PRIMARY KEY (id);


--
-- Name: firmwares firmwares_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY firmwares
    ADD CONSTRAINT firmwares_pkey PRIMARY KEY (id);


--
-- Name: measurements measurements_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY measurements
    ADD CONSTRAINT measurements_pkey PRIMARY KEY (measurementid);


--
-- Name: profiledata profiledata_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY profiledata
    ADD CONSTRAINT profiledata_pkey PRIMARY KEY (profiledataid);


--
-- Name: profiles profiles_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY profiles
    ADD CONSTRAINT profiles_pkey PRIMARY KEY (profileid);


--
-- Name: screenings screenings_measurementid_key; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY screenings
    ADD CONSTRAINT screenings_measurementid_key UNIQUE (measurementid);


--
-- Name: screenings screenings_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY screenings
    ADD CONSTRAINT screenings_pkey PRIMARY KEY (screeningid);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: hc; Owner: -
--

ALTER TABLE ONLY users
    ADD CONSTRAINT users_pkey PRIMARY KEY (userid);


--
-- Name: calibrations update_calibrations_updatedat; Type: TRIGGER; Schema: hc; Owner: -
--

CREATE TRIGGER update_calibrations_updatedat BEFORE UPDATE ON calibrations FOR EACH ROW EXECUTE PROCEDURE public.update_updatedat_column();


--
-- Name: measurements update_measurements_updatedat; Type: TRIGGER; Schema: hc; Owner: -
--

CREATE TRIGGER update_measurements_updatedat BEFORE UPDATE ON measurements FOR EACH ROW EXECUTE PROCEDURE public.update_updatedat_column();


--
-- Name: profiledata update_profiledata_updatedat; Type: TRIGGER; Schema: hc; Owner: -
--

CREATE TRIGGER update_profiledata_updatedat BEFORE UPDATE ON profiledata FOR EACH ROW EXECUTE PROCEDURE public.update_updatedat_column();


--
-- Name: profiles update_profiles_updatedat; Type: TRIGGER; Schema: hc; Owner: -
--

CREATE TRIGGER update_profiles_updatedat BEFORE UPDATE ON profiles FOR EACH ROW EXECUTE PROCEDURE public.update_updatedat_column();


--
-- Name: users update_users_updatedat; Type: TRIGGER; Schema: hc; Owner: -
--

CREATE TRIGGER update_users_updatedat BEFORE UPDATE ON users FOR EACH ROW EXECUTE PROCEDURE public.update_updatedat_column();


--
-- PostgreSQL database dump complete
--

