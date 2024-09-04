package algorithm.lang.java;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class StringStudy {
    public static void main(String[] args) {
        // 문자열 (string)
        // - CharSequence Interface의 구현체 중 하나
        // ㄴ 유사 구현체: StringBuilder, StringBuffer


        // 1. 선언(생성) |=====================================================================================
        // : 원시타입은 아니지만, 예외적으로 new 키워드없이 생성가능
        String text = "This is test text";
        String text_newkw = new String("This is test text with 'new' keyword!");

        // 2. 정보 가져오기 |=====================================================================================
        // 2-1. 문자열 길이
        System.out.println( "'text' length is: " + text.length() );

        // 3. 수정 |=====================================================================================
        // 3-1. 문자열 연결

        // 권장방법
        StringBuilder sb = new StringBuilder("Stringbuilder test - ");
        sb.append( "concat_text" );
        System.out.println(sb);

        // 지양방법
        System.out.println( text.concat( "test_string" ) ); // concat 결과만 return하고, 원본에 반영하진 않음
        System.out.println( text + "test2_string" ); // 상동; 원본에 반영되지 않음

        // String.concat()
        // : StringConcatHelper.simpleConcat() 메서드 기반인데,
        // ㄴ 해당 메서드가 마지막에 return할 때 새로운 String 객체를 생성하므로 결론적으로 성능이 저하됨

        // '+' 연산
        // : java 내부적으로 컴파일 시 컴파일러가 자동으로 StringBuilder로 변환하여 처리하도록 구현되어있음
        // ㄴ 반복문 내에서 해당 연산을 사용한다면, 반복문의 순회횟수만큼 StringBuilder 객체가 생성되므로 결론적으로 성능이 저하됨

        // 4. 비교 |=====================================================================================
        // ㄴ> String.equals(arg1): arg1으로 입력받은 문자열과 현재 문자열이 동일한지 비교 (return boolean)
        System.out.printf("text & text_newkw compare: %s\n",
            text.equals( text_newkw ) ? "same" : "diff"
        );

        // 5. 대치 |=====================================================================================
        // ㄴ> String.replace(arg1, arg2) -> String : arg1를 찾아 arg2로 '모두'변경 (arg1 regex '불가능')
        // ㄴ> String.replaceAll(arg1, arg2) -> String : arg1를 찾아 arg2로 '모두'변경 (arg1 regex 가능)
        // ㄴ> String.replaceFirst(arg1, arg2) -> String : arg1를 찾아 arg2로 '최초 1개만' 변경 (arg1 regex 가능)
        String rep_test = "REPLACE_TEXT_PLZ[ABCDEFG-ABCDEFG-ABCDEFG-ABCDEFG]";
        System.out.println( rep_test.replace("ABCDEFG", "[CHANGED:D]") ); // print: REPLACE_TEXT_PLZ[[CHANGED:D]-[CHANGED:D]-[CHANGED:D]-[CHANGED:D]]
        System.out.println( rep_test.replaceAll("ABCDEFG", "[CHANGED:D]") ); // print: REPLACE_TEXT_PLZ[[CHANGED:D]-[CHANGED:D]-[CHANGED:D]-[CHANGED:D]]
        System.out.println( rep_test.replaceFirst("ABCDEFG", "[CHANGED:D]") ); // print: REPLACE_TEXT_PLZ[[CHANGED:D]-[CHANGED:D]-ABCDEFG-ABCDEFG]

        // String.replace() vs. String.replaceAll()
        // ㄴ String.replace: 인자로 정규식을 지원하지 않으며, 구현상으로도 StringLatin1.replace() 메서드를 호출하여 while문을 통해 모든 일치대상을 변경함
        // ㄴ String.replaceAll: 인자로 정규식을 지원하며, 이로 인해 구현상으로도 Pattern.compile()이 우선적으로 실행되며 정규식을 parsing하는 과정이 발생, 성능적 지연이 발생함
        // => 단순히 일치하는 문자열을 대치한다면 replace(), 정규식을 사용하여 복잡한 문자열을 대치한다면 replaceAll()을 사용할 것

        // 6. 분할 |=====================================================================================
        String spl_test = "010-1234-5678";
        String[] spl_res = spl_test.split("-");
        for ( String value : spl_res ) {
            System.out.println(value);
        }
    }


}
