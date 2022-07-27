FROM node as base
WORKDIR /app
COPY . .
RUN npm install
RUN npm install -g pm2
CMD pm2-runtime start ecosystem.config.js
