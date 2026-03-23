// Online Java Compiler
// Use this editor to write, compile and run your Java code online

class Animal {
 protected String name;
 protected String type; // land, water, air
 protected int maxLife;
 
 public Animal(String name, String type, int maxLife){
     this.name = name;
     this.type = type;
     this.maxLife = maxLife;
 }
 
 public void about(){
     System.out.println(this.name + " is a " + this.type + " animal that usually lives upto " + this.maxLife + " years long!");
 }
 
 public void doSomething(){
     if(this.type.toLowerCase().trim().equals("land")) System.out.println("Animal Runssss!!!");
     else if(this.type.toLowerCase().trim().equals("air")) System.out.println("Animal Flysss!!!");
     else if(this.type.toLowerCase().trim().equals("water")) System.out.println("Animal Swimmsss!!!");
     else System.out.println("Animal is currently sleeping!!!");
 }
}

class Dog extends Animal {
    public String petName;
    public int currentAge;
    public Dog(String name, String type, int maxAge, String petName, int currentAge){
        super(name, type, maxAge);
        this.petName = petName;
        this.currentAge = currentAge; 
    }
    
    public void fetch(String thing){
        System.out.println("I have thrown a " + thing + ", my dog " + this.name + " who is " + this.currentAge + " years old, will fetch it...yayyy");
    }
}



class Main {
    public static void main(String[] args){
        Animal a1 = new Animal("Dog", " Land", 12);
        Dog tommy = new Dog("Dog", "Land", 12, "Tommy", 4);
        tommy.about();
        tommy.fetch("Ball");
    }
}
