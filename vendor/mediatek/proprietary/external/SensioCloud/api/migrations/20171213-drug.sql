CREATE TYPE drugtype AS enum ('none', 'hypertension', 'hypotension');
ALTER TABLE hc.profiledata ADD COLUMN drug drugtype NOT NULL DEFAULT 'none';
ALTER TABLE hc.profiledata ADD COLUMN drugtime smallint;
