import requests
from PIL import Image
from io import BytesIO
import matplotlib.pyplot as plt

# NASA APOD API URL
apod_url = 'https://api.nasa.gov/planetary/apod'

api_key = 'nope'

# Parameters for the API request
params = {
    'api_key': api_key,
    'hd': 'True'  # Set 'hd' to 'True' for high-definition images
}

try:
    # Make a GET request to the APOD API
    response = requests.get(apod_url, params=params)
    response.raise_for_status()  # Check for HTTP errors

    # Parse the JSON response
    apod_data = response.json()

    # Print APOD information
    print("Title:", apod_data['title'])
    print("Date:", apod_data['date'])
    print("Explanation:", apod_data['explanation'])

    # Get the image URL
    image_url = apod_data['hdurl'] if 'hdurl' in apod_data else apod_data['url']

    # Retrieve and display the image
    response = requests.get(image_url)
    img = Image.open(BytesIO(response.content))

    plt.imshow(img)
    plt.axis('off')
    plt.show()

except requests.exceptions.RequestException as e:
    print("Error:", e)
except Exception as ex:
    print("An error occurred:", ex)
