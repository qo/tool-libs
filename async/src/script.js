const apiKey = "YOUR_API_KEY"

const weatherDiv = document.getElementById("weather")
const cityInput = document.getElementById("cityInput")

async function getWeather() {

  const city = cityInput.value
  const apiUrl = `https://cors-anywhere.herokuapp.com/http://samples.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}`
  try {
    const response = await fetch(apiUrl)

    if (!response.ok) {
      throw new Error("Ошибка при получении данных о погоде: ${response.status} ${response.statusText}")
    }

    const data = await response.json()
    const temp = data.main.temp
    const desc = data.weather[0].description
    
    weatherDiv.innerHTML = `
      <h2>Погода в городе ${city}:</h2>
      <p>Температура: ${temp}*F</p>
      <p>Описание: ${desc}</p>
    `

  } catch (error) {
    weatherDiv.innnerHTML = `
      <h2>${error.message}</h2>
    `
  }

}
