FROM ubuntu:16.04
MAINTAINER em.chang@mediatek.com

RUN apt-get update && apt-get install -y curl

RUN curl -sL https://www.postgresql.org/media/keys/ACCC4CF8.asc | apt-key add -
RUN echo "deb http://apt.postgresql.org/pub/repos/apt/ xenial-pgdg main" > /etc/apt/sources.list.d/pgdg.list
RUN curl -sL https://deb.nodesource.com/setup_6.x | bash -

RUN apt-get install -y build-essential postgresql-client-9.6 libpq-dev nodejs
RUN npm install forever -g

COPY . /code/
WORKDIR /code

RUN cd /code && npm install

CMD ["forever", "app.js"]
