FROM ubuntu:16.04
MAINTAINER em.chang@mediatek.com

# Set the debconf frontend to Noninteractive
# RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

RUN apt-get update && apt-get install -y -q wget
# RUN apt-get update && apt-get install -y -q wget apt-transport-https lsb-release ca-certificates

# Download certificate and key from the customer portal (https://cs.nginx.com)
# and copy to the build context
# ADD nginx-repo.crt /etc/ssl/nginx/
# ADD nginx-repo.key /etc/ssl/nginx/

# Get other files required for installation
RUN wget -q -O - http://nginx.org/keys/nginx_signing.key | apt-key add -

RUN printf "deb http://nginx.org/packages/ubuntu/ xenial nginx\ndeb-src http://nginx.org/packages/ubuntu/ xenial nginx" >/etc/apt/sources.list

# Install NGINX Plus
RUN apt-get update && apt-get install -y nginx

# forward request logs to Docker log collector
RUN ln -sf /dev/stdout /var/log/nginx/access.log
RUN ln -sf /dev/stderr /var/log/nginx/error.log

# EXPOSE 80 443
COPY ./nginx.conf /etc/nginx/conf.d/
EXPOSE 3000
CMD ["nginx", "-g", "daemon off;"]
