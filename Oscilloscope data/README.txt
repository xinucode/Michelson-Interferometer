README for oscilloscope data
=======================================================

There are three forms of each data set:

raw data - what comes directly out of the oscilloscope
combined files - each data point (multiple files) after
    processed by parse.cpp
final excel sheet - includes the averaged FFT of each 
    data point along with relevant graphs
    
=======================================================
There are three data sets:

4-4-19
4-8-19
4-11-19
All

=======================================================
Details on each data set are described below:
---------------------------------------------

4-4-19:
Description: This data tests the optimal driving* 
frequency for detecting the audio frequency of 440 Hz. 
The driving frequency was changed and tested at 1 Hz,
5 Hz, 10 Hz, 20 Hz, 30 Hz, 40 Hz, and 50 Hz. The driving
voltage was maintained at 5 V.

* "driving" referes to the function generator settings
which in turn controlled the PZT (outlined in Final 
Report)

The columns are named similar to as follows:
doors_5V_10Hz
(nickname_driving-voltage_driving-frequency)

Results: Further details are specified in the Final
Report, but some important details did not make into
the report. For the larger voltages you see there are 
“sidebands”, i.e. peaks at the sum frequency and 
difference frequency of acoustic source and pzt. The 
math of this is actually pretty simple and similar to 
“beating”

---------------------------------------------

4-8-19:
Description: This data is results from the optimal 
driving voltage. The driving frequency was set at 1 Hz. 
The audio frequency was set to 440 Hz. The driving 
voltageswere set to 1 V, 5 V, and 10 V. The columns are 
named in the same manner as for 4-4-19 data. 

Results: The only changes are to the frequency of the
FFT at 0 Hz. This is due to the nature of how the FFT 
is calculated. Otherwise, there is no apparent changes.
More details in Final Report

---------------------------------------------

4-11-19:
Description: These results are to test the base noise
without any audio frequencies. We also tested with and
without the PZT. The parameters for each column are as
follows:

----------driving_voltage-driving_frequency-audio_frequency-audio_strength
gentlewzt:
noisewzt: 5V              1Hz               0               0
quietwpzt:
softwzt:
noise:    0               0                 0               0
hcope:    5V              1 Hz              100 Hz 
icope:    5V              1 Hz              100 Hz 
kcope:    5V              1 Hz              100 Hz 
pcope:    5V              1 Hz              900 Hz   
tcope:    5V              1 Hz              900 Hz   
wcope:    5V              1 Hz              900 Hz 

---------------------------------------------

All:
Description: This tests a range of audio frequencies at
different decibal levels to see which frequencies have the 
most strength in our readings. The decibel levels are at 
unspecified levels of 1,2,3,4,5,6,7,8 and 9. The 
frequencies are tested at 100, 200, 300, 400, 500, 
600 (incomplete), 700, 800, 900. The settings on the 
function generator are 1 Hz and 5 V. 

Results: In the final report





