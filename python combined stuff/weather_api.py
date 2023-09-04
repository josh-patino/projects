import requests

API_KEY = 'LOL' #change out before git hub push

# Function to fetch weather data by city name
def get_weather_by_city(city_name):
    base_url = 'http://api.openweathermap.org/data/2.5/weather'
    params = {'q': city_name, 'appid': API_KEY, 'units': 'metric'}
    # You can change units to 'imperial' for Fahrenheit

    try:
        response = requests.get(base_url, params=params)
        data = response.json()
        if response.status_code == 200:
            return data
        else:
            return None
    except requests.exceptions.RequestException as e:
        print("Error:", e)
        return None

def main():
    city_name = input("Enter the city name: ")
    weather_data = get_weather_by_city(city_name)

    if weather_data:
        print(f"Weather in {city_name}:")
        print(f"Temperature: {weather_data['main']['temp']}°C")
        print(f"Description: {weather_data['weather'][0]['description']}")
    else:
        print("Weather data not available for the given city.")

if __name__ == '__main__':
    main()