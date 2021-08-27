--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'SQL_ASCII';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

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
-- Name: users; Type: TABLE; Schema: hc; Owner: -; Tablespace: 
--

CREATE TABLE users (
    useridseq bigint NOT NULL,
    userid character varying(12) NOT NULL,
    username character varying(50),
    password character varying(60) NOT NULL,
    ispaiduser boolean DEFAULT false NOT NULL,
    status boolean DEFAULT true NOT NULL,
    createdat timestamp without time zone DEFAULT now() NOT NULL,
    createdby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL,
    updatedat timestamp without time zone DEFAULT now() NOT NULL,
    updatedby character varying(12) DEFAULT 'SYSTEM'::character varying NOT NULL
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
-- Name: useridseq; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY users ALTER COLUMN useridseq SET DEFAULT nextval('users_useridseq_seq'::regclass);


--
-- Name: userid; Type: DEFAULT; Schema: hc; Owner: -
--

ALTER TABLE ONLY users ALTER COLUMN userid SET DEFAULT ('U'::text || public.charactorize(public.feistelcipherbigint(currval('users_useridseq_seq'::regclass), (89336549)::bigint, 9137831701::bigint, 84189318179::bigint)));


--
-- Name: users_pkey; Type: CONSTRAINT; Schema: hc; Owner: -; Tablespace: 
--

ALTER TABLE ONLY users
    ADD CONSTRAINT users_pkey PRIMARY KEY (userid);


--
-- Name: update_users_updatedat; Type: TRIGGER; Schema: hc; Owner: -
--

CREATE TRIGGER update_users_updatedat BEFORE UPDATE ON users FOR EACH ROW EXECUTE PROCEDURE public.update_updatedat_column();


--
-- PostgreSQL database dump complete
--

