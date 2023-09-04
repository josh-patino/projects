//using System.Reflection.Emit;
// See https://aka.ms/new-console-template for more information

public abstract class PizzaStore {
    public Pizza orderPizza(string type) {
        Pizza pizza = createPizza(type);

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
    protected abstract Pizza createPizza(string item);
}

public class NYPizzaStore : PizzaStore {
    
     protected override Pizza createPizza(string item) {
        Pizza pizza = null; 
       switch (item)
            {
                case "cheese":
                    pizza = new NYCheesePizza();
                    break;
                case "veggie":
                    pizza = new NYCheesePizza();
                    break;
                case "clam":
                    pizza = new NYCheesePizza();
                    break;
                case "pepperoni":
                    pizza = new NYCheesePizza();
                    break;
            }
        return pizza; 
    }
}

public class CHIPizzaStore : PizzaStore {
    protected override Pizza createPizza(string item) {
        Pizza pizza = null; 

         switch (item)
            {
                case "cheese":
                    pizza = new CHICheesePizza();
                    break;
                case "veggie":
                    pizza = new NYCheesePizza();
                    break;
                case "clam":
                    pizza = new NYCheesePizza();
                    break;
                case "pepperoni":
                    pizza = new NYCheesePizza();
                    break;
            }
        return pizza;
    }
}


public abstract class Pizza {
    public string dough;
    public string name;
    public string sauce; 
    public List<string> toppings = new List<string>();

    public virtual void prepare() {
        System.Console.WriteLine("preparing " + name);
        System.Console.WriteLine("tossing dough..");
        System.Console.WriteLine("adding secret sauce...");
        System.Console.WriteLine("adding toppings: ");
        foreach(string topping in toppings){
            System.Console.WriteLine(" " + topping);
        }
    }

    public virtual void bake() {
        System.Console.WriteLine("baking in pizza air fryer..");
    }

    public virtual void cut(){
        System.Console.WriteLine("cutting pizza... into 9 slices");
    }

    public virtual void box(){
        System.Console.WriteLine("Boxing in an eco freindly box..");
    }

    public string getName(){
        return name;
    }
}

public class NYCheesePizza : Pizza {
    public NYCheesePizza(){
        name = "NY style cheese pizza!";
        dough = "thin crust dough";
        sauce = "mariana sauce.. oh yea!";

        toppings.Add("grated cheese");
    }
}

public class CHICheesePizza : Pizza {
    public CHICheesePizza(){
        name = "Chicago GOAT PIZZA";
        dough = "extra thick ccrust dough";
        sauce = "plum tomato sauce";

        toppings.Add("shreedded mozz");
    }

    public override void cut() {
        System.Console.WriteLine("cutting into sqaures");
    }
}






public class PizzaTestDrive {
[STAThread]
    static void Main(){
        PizzaStore nyStore = new NYPizzaStore();
        Pizza pizza = nyStore.orderPizza("cheese");
        System.Console.WriteLine("Ethan ordered a " + pizza.getName() + " \n");

        PizzaStore chicagoStore = new CHIPizzaStore();
        pizza = chicagoStore.orderPizza("cheese");
        System.Console.WriteLine("josh ordered a " + pizza.getName());

    }
}