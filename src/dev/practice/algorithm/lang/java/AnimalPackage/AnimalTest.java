package algorithm.lang.java.AnimalPackage;

abstract public class AnimalTest {
    // 추상 클래스: 이 클래스를 상속받아 구현한 다른 클래스만 사용 가능하며, 추상 클래스로 선언된 클래스 자체는 생성자를 통한 생성이 불가
    // ㄴ 사용이유: 인터페이스에서 사용이 불가한 일반적인 필드, 메서드, 생성자 선언 가능하기 때문
    // => 중복되는 클래스 멤버들을 통합/확장 하고 '클래스 간 연관관계'를 만드는 것에 초점

    public String name;
    public int age;
    public AnimalType animalType;

    public AnimalTest( String name, int age, AnimalType animalType) {
        this.name = name;
        this.age = age;
        this.animalType = animalType;
    }

    public String getName() {
        return this.name;
    }

    public void walk() {
        StringBuilder sb = new StringBuilder();
        sb.append( this.getName() )
                .append("가 걸어가고 있습니다.");

        System.out.println(sb);
    }
}
