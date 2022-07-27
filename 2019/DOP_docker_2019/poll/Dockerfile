FROM python
WORKDIR /app
COPY . .
EXPOSE 80
RUN pip install -r requirements.txt
CMD flask run --host=0.0.0.0 --port=80