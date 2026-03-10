package algorithm.lang.java;

public class ClassStudy {
    // 클래스 (Class)
    // : 표현하고자 하는 대상의 공통속성을 한곳에 정리해둔 것 (= 객체의 속성)

    // 필드, 멤버변수 (Field, Member Variable): 지정된 접근제어자의 종류에 따라 클래스 내외에서 사용할 수 있는 공통 데이터
    private int priv_value = 1; // private: 현재 class 내부에서 접근가능
    int def_value = 2; // default: 같은 패키지 내부에서 접근가능
    protected int protect_value = 3; // protected: 같은 패키지 내부, 본 클래스 상속 class에서 접근가능
    public int pub_value = 4; // public: 모든 패키지에서 접근가능

    // 생성자 (Constructor): 이 Class를 통해 객체가 만들어질 때 설정명령을 내리는 코드
    public ClassStudy() {
        // ... 코드 작성
        this.priv_value = 100; // 필드는 this 키워드로 접근
    }

    // 메서드 (Method): 객체에 대한 어떠한 작업을 수행하는 함수
    public void test() {
        System.out.println("TEST METHOD");
    }
}
