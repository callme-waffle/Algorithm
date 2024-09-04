package algorithm.lang.java;

public interface InterfaceStudy {
    // 필드
    // : 상수만 선언 가능하며, 특정 필드의 존재를 구현체에 강제할 수 없음

//    public static boolean is_eatable; // 불가: 인터페이스는 '상수'만 선언 가능 (public static final)
    public static final boolean is_eatable = true; // 가능: 상수고, 초기화되었기 떄문
    boolean is_fresh = true; // public static final 생략 가능

    // 메서드

    // 1. 인스턴스 메서드
    // : '추상메서드'의 '이름'만 지정 가능 (= 직접적 구현불가)

//    public void bark() {}
    public abstract void bark();
    void hungry(); // public abstract 생략 가능

    // 2. default 메서드
    // : (Java 8~) default 메서드인 경우에 한하여 메서드 구현체 추가가능
    // ㄴ 추가이유: 하위호환성을 위함 ( 구현체 수정없이 전역 기능추가가 필요할 때 사용 )
    default String barkEx() {
        // 앞에 붙은 'default'는 접근제어자를 나타내는 'default'가 아님
        // (접근제어자의 default는 아예 안적혀야 함; 메서드 앞 'default'는 default method를 의미)
        return "어흥~";
    }

    // - 여러 interface들의 다중 implements 간 default 메서드가 충돌될 경우, 구현체의 overriding이 강제
    // - interface implments와 class extends 간 default 메서드가 충돌발생 시, default 메서드가 무시됨
    // ㄴ 접근하기 위해서는 [인터페이스명].super.[default메서드명]으로 접근

    // 3. static 메서드
    // : (Java 8~) interface 내에서도 구현가능

    // 4. private 메서드
    // : (Java 9~) interface 내부에서만 사용가능한 메서드
}
