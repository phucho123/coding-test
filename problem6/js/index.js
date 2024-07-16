const API_KEY = '99309332c62f769a0d4a28eaecd139b4';
const DEFAULT = '--';
const citySearchInput = document.querySelector('#city-search');
const cityDisplay = document.querySelector('.city-display');
const weatherDescription = document.querySelector('.weather-description');
const weatherImage = document.querySelector('.weather-image');
const temperatureDisplay = document.querySelector('.temperature-display');

const sunriseTime = document.querySelector('.sunrise-time');
const sunsetTime = document.querySelector('.sunset-time');
const humidityLevel = document.querySelector('.humidity-level');
const windVelocity = document.querySelector('.wind-velocity');

citySearchInput.addEventListener('change', async (event) => {
    try {
        const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${event.target.value}&appid=${API_KEY}&units=metric&lang=vi`);
        const weatherData = await response.json();
        console.log('Weather Data:', weatherData);

        cityDisplay.textContent = weatherData.name || DEFAULT;
        weatherDescription.textContent = weatherData.weather[0].description || DEFAULT;
        weatherImage.setAttribute('src', `http://openweathermap.org/img/wn/${weatherData.weather[0].icon}@2x.png`);
        temperatureDisplay.textContent = Math.round(weatherData.main.temp) || DEFAULT;

        sunriseTime.textContent = moment.unix(weatherData.sys.sunrise).format('H:mm') || DEFAULT;
        sunsetTime.textContent = moment.unix(weatherData.sys.sunset).format('H:mm') || DEFAULT;
        humidityLevel.textContent = weatherData.main.humidity || DEFAULT;
        windVelocity.textContent = (weatherData.wind.speed * 3.6).toFixed(2) || DEFAULT;
    } catch (error) {
        console.error('Error fetching weather data:', error);
        cityDisplay.textContent = weatherDescription.textContent = temperatureDisplay.textContent = DEFAULT;
        sunriseTime.textContent = sunsetTime.textContent = humidityLevel.textContent = windVelocity.textContent = DEFAULT;
    }
});
