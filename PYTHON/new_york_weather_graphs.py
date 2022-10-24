# Import Meteostat library and dependencies
from datetime import datetime
import matplotlib.pyplot as plt
from meteostat import Point, Daily, Monthly

# Set time period for this year
start = datetime(int(datetime.today().strftime('%Y')) , 1, 1)
end = datetime.today().strftime('%Y, %m, %d')

# Set time period for last year
lastyearstart = datetime(int(datetime.today().strftime('%Y'))-1, 1, 1)
lastyearend = str(int(datetime.today().strftime('%Y'))-1)+ datetime.today().strftime(', %m, %d')

# Get daily data for this year
data = Daily('KNYC0', start, end)
data = data.fetch()

# Get Monthly data for this year
data3 = Monthly('KNYC0', start, end)
data3 = data3.fetch()

# Get Monthly data for last year
data4 = Monthly('KNYC0', lastyearstart, lastyearend)
data4 = data4.fetch()

# Get daily data for last year
data1 = Daily('KNYC0', lastyearstart, lastyearend)
data1 = data1.fetch()

print('Comparision of New Yor daily weather statistics between this year and last year')
print()

# Plot line chart including average, minimum and maximum temperature
# This years daily weather stats for new york
data.plot(y=['tavg', 'tmin', 'tmax'])
plt.title("New York Daily Weather Statistics (Average/ Minimum/ Maximum) Temperature for " + datetime.today().strftime('%Y'))

# Lats years daily weather stats for new york
data1.plot(y=['tavg', 'tmin', 'tmax'])
plt.title("New York Daily Weather Statistics (Average/ Minimum/ Maximum) Temperature for " + str(int(datetime.today().strftime('%Y'))-1))

# This years monthly weather stats for new york
data3.plot(y=['tavg', 'tmin', 'tmax'])
plt.title("New York Monthly Weather Statistics (Average/ Minimum/ Maximum) Temperature for " + datetime.today().strftime('%Y'))

# This years monthly weather stats for new york
data4.plot(y=['tavg', 'tmin', 'tmax'])
plt.title("New York Monthly Weather Statistics (Average/ Minimum/ Maximum) Temperature for " + str(int(datetime.today().strftime('%Y'))-1))
plt.show()
