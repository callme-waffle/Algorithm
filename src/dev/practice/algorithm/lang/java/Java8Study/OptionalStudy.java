package algorithm.lang.java.Java8Study;

import java.util.Optional;
import java.util.Random;

public class OptionalStudy {

    static class Test {
        private int value1;
        private int value2;
        private String value3;
        private Test next;

        // constructor
        public Test(int value1, int value2, String value3) {
            this.value1 = value1;
            this.value2 = value2;
            this.value3 = value3;
        }

        public Test(int value1, int value2, String value3, Test next) {
            this.value1 = value1;
            this.value2 = value2;
            this.value3 = value3;
            this.next = next;
        }

        // getter
        public int getValue1() {
            return value1;
        }

        public int getValue2() {
            return value2;
        }

        public String getValue3() {
            return value3;
        }

        public Test getNext() {
            return next;
        }

        // setter
        public void setNext(Test next) {
            this.next = next;
        }
    }

    private static Optional<Test> getTestInfo() {
        if ( new Random().nextInt(2) > 0 )
            return Optional.empty(); // 비어있는 Optional 객체는 Optional.empty()를 통해 생성

        // Optional.of() 에 제공되는 인자는 null이면 안됨 (null일 수 있다면 ofNullable() 사용)
        return Optional.of( new Test( 1, 2, "OPTIONAL_TEST" ) );
    }

    public static void main(String[] args) {
        Optional<Test> data = OptionalStudy.getTestInfo();

        // 조회: 값 가져오기
        Test testObjA = data.get(); // 값이 없으면 throw NoSuchElementException
        Test testObjB = data.orElse( new Test( -1, -1, "VALUE_NOT_FOUND" ) );
        // ㄴ> 값이 없으면 제공된 인자의 값을 사용하여 설정
        Test testObjC = data.orElseGet( () -> new Test( -1, -1, "VALUE_NOT_FOUND" ) );
        // ㄴ> 값이 없으면 제공된 supplier를 실행하여 그 결과를 값으로 사용하여 설정

        // 조회: 값 존재여부 확인
        System.out.printf( "[Optional] isPresent: 값의 존재여부 (:데이터가 존재하는지) 체크 | %s\n", data.isPresent() );
        System.out.printf( "[Optional] isEmpty: 값의 존재여부 (:데이터가 없는지) 체크 | %s\n", data.isEmpty() );

        // 연속작업: 존재우무에 따른 추가작업
        data.ifPresent( // : 데이터가 '존재할 때' 수행할 작업을 설정할 수 있음
                ( Test d ) -> {
                    System.out.println( "[Optional] ifPresent(): 데이터가 존재함!" );
                }
        );
        data.ifPresentOrElse( // : 데이터가 '존재할 때' & '존재하지 않을 때' 수행할 작업을 모두 설정할 수 있음
                ( Test d ) -> {
                    System.out.println( "[Optional] ifPresentOrElse(): 데이터가 존재함!" );
                },
                () -> {
                    System.out.println( "[Optional] ifPresentOrElse(): 데이터가 존재하지 않음!" );
                }
        );

        // 연속작업: 조건부 데이터 삭제
        data.filter( ( Test test ) -> test.value1 > 10 );

        // 연속작업: 데이터 수정
        data.map( ( Test prev ) -> {
            prev.setNext( prev );
            return prev;
        } );
    }
}
