package algorithm.lang.java.CollectionStudy;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class SetStudy {
    // 3. Set
    // : 데이터의 포함여부 확인을 위해 사용하는 자료형

    // 기본사용
    // : Set test_set = new ~

    public static void main(String[] args) {
        // 1. HashSet
        Set<Integer> setA = new HashSet();

        // 추가
        setA.add(3);
        setA.add(2);
        setA.add(6);
        setA.add(5);
        setA.add(10);
        for ( int i = 0; i < 5; i++ ) setA.add(i); // 앞에 추가되어 중복되는 값들은 무시

        // 출력
        System.out.printf( "Hash Set: 1st print | %s\n", setA ); // 춫력순서를 예측/보장할 수 없음

        // 삭제
        setA.remove( 3 );
        setA.remove( 2 );
        setA.remove( 6 );

        System.out.printf( "Hash Set: 2nd print | %s\n", setA );

        // 2. TreeSet
        Set<Integer> setB = new TreeSet();
//        Set<Integer> setB = new TreeSet( ( a, b ) -> (int)b - (int)a ); // Comparator를 인자로 lambda 문법을 사용하여 제공

        // 추가
        setB.add(3);
        setB.add(2);
        setB.add(6);
        setB.add(5);
        setB.add(10);
        for ( int i = 0; i < 5; i++ ) setB.add(i); // 앞에 추가되어 중복되는 값들은 무시

        // 출력
        System.out.printf( "Tree Set: 1st print | %s\n", setB ); // 출력순서는 오름차순 정렬상태로 보장됨 (생성자로 Comparator를 제공시 예욑)

        // 삭제
        setB.remove( 3 );
        setB.remove( 2 );
        setB.remove( 6 );

        System.out.printf( "Tree Set: 2nd print | %s\n", setB );
    }
}
