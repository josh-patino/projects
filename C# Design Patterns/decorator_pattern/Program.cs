using System.Reflection.Metadata.Ecma335;
using System;
//component
public abstract class Beverage {
	public string description = "unknown beverage";
	
	public virtual string getDescription(){
		return description; 
	}
	//this will be changed with each beverage + decorators 
	public abstract double cost();
}

//Decorator class
public abstract class CondimentDecorator : Beverage {
	public abstract override String getDescription();
}

//expresso concrete component class
public class Expresso : Beverage {
	public Expresso(){
		description = "Expresso"; 
	}
	
	public override double cost() {
		return 1.99;
	}
}

//house blend concrete component class
public class HouseBlend : Beverage {
    private double _houseBlendCost = .89;
    public HouseBlend(){
        description = "house blend coffee";
    }

    public override double cost()
    {
        return .89;
    }
}

//dark roast concrete component class 
//decaf concrete component class TODO


//condiment concrete decorators
public class Mocha : CondimentDecorator {
    Beverage beverage;
    public Mocha(Beverage beverage){
        this.beverage = beverage;
    }
    public override string getDescription(){
        return beverage.getDescription() + ", Mocha";
    }

    public override double cost(){
        return .20 + beverage.cost();
    }
}
public class Whip : CondimentDecorator {
    Beverage beverage;
    public Whip(Beverage beverage){
        this.beverage = beverage;
    }
    public override string getDescription(){
        return beverage.getDescription() + ", Whip";
    }

    public override double cost(){
        return .10 + beverage.cost();
    }
}


class Untitled
{
	static void Main(string[] args)
	{
		System.Console.WriteLine("hello world");

        Beverage beverage = new Expresso();
        System.Console.WriteLine(beverage.getDescription() + " $" + beverage.cost());

        Beverage bev2 = new HouseBlend(); // make houseblend
        bev2 = new Mocha(bev2); //wrap it in a mocha 
        bev2 = new Mocha(bev2); //wrap it in a mocha 
        bev2 = new Whip(bev2); 
        System.Console.WriteLine(bev2.getDescription() + " $" + bev2.cost());

	}
}