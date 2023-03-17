using System;
#nullable disable

//fly duck behavior
public interface FlyBehavior {
	void fly();
}
//flying with wings class derives from fly behavior
public class FlyWithWings : FlyBehavior {
	public void fly() {
		Console.WriteLine("i can fly");
	}
}
//flying with no wings class derives from fly behavior
public class FlyNoWings : FlyBehavior {
	public void fly(){
        Console.WriteLine("I cannot fly"); 
    }
}
//flying behavior interface 
public class FlyRocketPowered : FlyBehavior {
    public  void fly(){
        System.Console.WriteLine("flying with 9 rockets up my ass");
    }
}

//quack behavior interface 
public interface QuackBehavior {
    public void quack();
}
//quack behavior interface 
public class MuteQuack : QuackBehavior {
    public void quack(){
        System.Console.WriteLine("<<whole lotta silence>>");
    }
}
//quack behavior interface 
public class Squeak : QuackBehavior {
    public void quack()
    {
        System.Console.WriteLine("i squeak like one three");
    }
}
//quack behavior interface 
public class Quack : QuackBehavior {
    public void quack(){
        Console.WriteLine("Quack!1");
    }
}






//duck class
public abstract class Duck {
    
	public FlyBehavior flyBehavior;
    public QuackBehavior quackBehavior;
    public Duck(){}
    public abstract void Display();
    public void performFly(){
        flyBehavior.fly();
    }

    public void performQuack(){
        quackBehavior.quack();
    }

    public void swim(){
        System.Console.WriteLine("all ducks can float");
    }
    public void setFlyBehavior(FlyBehavior fb){
        flyBehavior = fb;
    }

    public void setQuackBehavior(QuackBehavior qb) {
        quackBehavior = qb;
    }
}

//mallard duck class
public class MallardDuck : Duck {
	public MallardDuck(){
        quackBehavior = new Quack();
        flyBehavior = new FlyWithWings(); 
    }
    public override void Display() {
        System.Console.WriteLine("im the biggest mallard duck");
    }
}

public class ModelDuck : Duck {
    public ModelDuck(){
        flyBehavior = new FlyNoWings();
        quackBehavior = new Quack();
    }

    public override void Display()
    {
        System.Console.WriteLine("im the biggest model bird");
    }
}


//main
public class DuckSimulator
{
	static void Main(string[] args)
	{
		
		Duck mallard = new MallardDuck();
		mallard.performQuack();
		mallard.performFly();


        Duck model = new ModelDuck();
        model.performFly();
        model.setFlyBehavior(new FlyRocketPowered());
        model.performFly();
        System.Console.WriteLine("please output");
	}
}