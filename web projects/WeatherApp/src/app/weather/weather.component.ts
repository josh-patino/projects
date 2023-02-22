import { Component, OnInit } from '@angular/core';
import { WeatherService } from '../weather.service';

@Component({
  selector: 'app-weather',
  templateUrl: './weather.component.html',
  styleUrls: ['./weather.component.css']
})
export class WeatherComponent implements OnInit {
  constructor(private weatherService: WeatherService){}
  //vars
myWeather: any; 
temperature: number = 0;
feelsLikeTemp: number = 0;
humidity: number = 0;
pressure: number = 0;
windSpeed:number = 0;
windGust: number = 0
summary: string = '';
iconURL: string = '';
cityName: string = '';
city: string = 'St. Louis';
units: string = 'imperial'; 

  ngOnInit(): void {
    this.getWeatherData(this.city);

  }
  onSubmit(){
    this.getWeatherData(this.city);
    this.city = '';
  }
  private getWeatherData(city: string) {
    this.weatherService.getWeather(this.city, this.units).subscribe({
      next:(res)=> { //error block, spit out data if we get anything
        console.log(res)
        this.myWeather = res; 
        console.log(this.myWeather)
        this.cityName = this.myWeather.name;
        this.temperature = Math.round(this.myWeather.main.temp);
        this.feelsLikeTemp=Math.round(this.myWeather.main.feels_like);
        this.humidity = this.myWeather.main.humidity;
        this.pressure = this.myWeather.main.pressure;
        this.summary = this.myWeather.weather[0].main;  
        this.iconURL = 'http://openweathermap.org/img/wn/' + this.myWeather.weather[0].icon+'@2x.png';
        this.windSpeed = Math.round(this.myWeather.wind.speed);
        this.windGust = Math.round(this.myWeather.wind.gust); 
      },
      error: (error) => console.log(error.message), // 
      complete:() => console.info('API call completed')
    })
  }
}
