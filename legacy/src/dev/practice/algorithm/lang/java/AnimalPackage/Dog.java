package algorithm.lang.java.AnimalPackage;

public class Dog extends AnimalTest {
    public Dog(String name, int age) {
        super(name, age, AnimalType.DOG);
    }

    @Override
    public void walk() {
        System.out.println("꼬리도 함께 흔들고 있네요");
    }
}
