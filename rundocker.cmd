REM Build the Docker image
docker build . -t cnh:1.0.0

REM Run the Docker container
docker run -it --rm cnh:1.0.0 bash