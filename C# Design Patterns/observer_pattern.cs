using System.Collections;
using System.Collections.Generic;

//"subject" interface, for adding, removing or notifying an obeserver
public interface Observable {
     void addObserver(Observer o);
     void removeObserver(Observer o);
     void notifyObservers();
}
//observer interface
public interface Observer {
     void update(float temp, float humidity, float pressure);
}
//expendable part, for adding extra displays 
public interface DisplayElement {
     void display();
}

//observeable class object, in this case a WeatherStation giving us data
public class WeatherStation : Observable {
    private List<Observer> _observers;
    private float _temp;
    private float _humidity;
    private float _pressure; 

    public WeatherStation(){
        _observers = new List<Observer>();
    }

    public void addObserver(Observer o){
        _observers.Add(o); 
    }

    public void removeObserver(Observer o){
            _observers.Remove(o);  
    }

    public void notifyObservers(){
        foreach(var observer in _observers) {
            observer.update(_temp, _humidity,_pressure);
        }
    }
    public void measurementsChanged(){
        notifyObservers();
    }

    public void setMeasurements(float temp, float humidity, float pressure) {
        this._humidity = humidity;
        this._pressure = pressure; 
        this._temp = temp;
        measurementsChanged();
        //update(_humidity,_pressure,_temp);
    }

    //other possible Weatherstation methods would go here.

}

public class CurrentConditionsDisplay : Observer, DisplayElement {
    private float _temp;
    private float _humidity;
    private float _pressure;
    private Observable _weatherStation;
    
    public CurrentConditionsDisplay(Observable weatherStation) {
        _weatherStation = weatherStation;
        _weatherStation.addObserver(this);
    }

    public void update(float temp, float humidity, float pressure) {
        this._temp = temp;
        this._humidity = humidity;
        display();
    }

    public void display(){
        System.Console.WriteLine("Current Conditions: " + _temp + "F degrees and " + _humidity + "percent humidity");
    }

}

public class WeatherStationData {
   static void Main(string[] args){
        WeatherStation weatherStation = new WeatherStation();
        CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherStation);

        weatherStation.setMeasurements(80.2f,65.2f,30.4f);
        weatherStation.setMeasurements(999.2f,999.2f,29.2f); 
    }
}