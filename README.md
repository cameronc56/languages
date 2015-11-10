# languages

idea: 

inspired by reddit comment 

I actually do a couple of steps. I read the first minute of music and make it a mono 22 kHz wav file (using ffmpeg). I read that into numpy. That's 1,323,000 data points.
I reduce this dataset down to 3000 floats. The first 1000 floats are blocks of frequencies (from an FFT) across blocks of time (6 seconds per block).
The second 1000 floats are just a straight average FFT of the entire music.
That last 1000 floats are an FFT of the energy levels of the song (square of the amplitude). This give a representation of the beats in the music.
I then take the vector of 3000 floats and do a minmax scaler to normalize each column to values between 0 and 1.
Next I do a principle component analysis and reduce the data set to 500 floating points.
And finally, I do a select K best algorithm to reduce the data set down to 100 values.
So each song is represented by 100 floating point numbers.
I can use these values not only to score the music, but I can also use support vector classifiers to guess the musical genre.
It works incredibly well at scoring and predicting. I use the numpy, sklearn package and google's "Neurallab" package. But am going to try out TensorFlow tonight.

create a web front end
user can upload mp3 or wav file, decoded with ffmpeg
file is analyzed for bpm, etc
numpy, sklearn, etc for playing with numbers
machine learning (tensorflow) to learn about songs and possibly predict music genre.
