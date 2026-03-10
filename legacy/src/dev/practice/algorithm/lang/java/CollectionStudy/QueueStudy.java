package algorithm.lang.java.CollectionStudy;

import java.util.Comparator;
import java.util.PriorityQueue;

public class QueueStudy {

    public static void main(String[] args) {
        // Queue
        // : FIFO 구조를 기반으로 하는 자료구조

        // 1. PriorityQueue
        // : 우선순위에 따라 출력순서가 정해지는 자료구조 / 배열기반

        // A) 자료형이 비교 가능한 값인 경우
        PriorityQueue<Integer> pq1 = new PriorityQueue();
        pq1.offer(1);
        pq1.offer(26);
        pq1.offer(12);

        while( !pq1.isEmpty() ) {
            System.out.printf( "Priority Queue dequeue: %d\n", pq1.poll() );
        }

        // B) 자료형이 비교가 불가한 값인 경우
        class Test {
            private int a;
            private int b;

            public Test(int a, int b) {
                this.a = a;
                this.b = b;
            }

            public int getA() {
                return a;
            }

            public int getB() {
                return b;
            }
        }

        // 비교할 대상에 대한 Comparator를 생성
        class TestComparator implements Comparator<Test> {
            @Override
            public int compare(Test o1, Test o2) {
                if ( o1.getA() == o2.getA() ) return o1.getB() - o2.getB();
                return o1.getA() - o2.getA();
            }
        }

        PriorityQueue<Test> pq2 = new PriorityQueue<>(10, new TestComparator() ); // 2번째 인자로 비교할 수 있는 Comparator 구현체를 제공
        pq2.offer( new Test( 20, 10 ) );
        pq2.offer( new Test( 10, 20 ) );
        pq2.offer( new Test( 10, 30 ) );

        while( !pq2.isEmpty() ) {
            Test polled = pq2.poll();
            System.out.printf( "Priority Queue (when uncomparable) dequeue: %d / %d\n", polled.getA(), polled.getB() );
        }
    }
}
