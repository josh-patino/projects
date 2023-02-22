import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class WeatherService {

  constructor(private http: HttpClient) { }

  getWeather(city:string, units: string){
    return this.http.get('https://api.openweathermap.org/data/2.5/weather?q='+ city +'&appid=1be97cc7bb89bb37fb12c3e455e70d6f&units=' + units);
  }

}
