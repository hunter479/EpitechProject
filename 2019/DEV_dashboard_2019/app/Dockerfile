FROM node
WORKDIR /app
COPY . .
WORKDIR /app/dashboard
RUN npm i npm@latest -g
RUN npm install .
EXPOSE 8080
CMD npm start