package algorithm.lang.java.VersionStudy.Java8;

import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StreamStudy {
    enum Sex {
        MALE,
        FEMALE
    }
    static class User {
        private String name;
        private int age;
        private final Sex sex;

        public User(String name, int age, Sex sex) {
            this.name = name;
            this.age = age;
            this.sex = sex;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public int getAge() {
            return age;
        }

        public void setAge(int age) {
            this.age = age;
        }

        public boolean onYearChange() {
            setAge( getAge()+1 );
            return true;
        }

        public Sex getSex() {
            return sex;
        }

    }
    public static void main(String[] args) {
        List <User> userList = new ArrayList<>();
        for ( int i = 0; i < 10; i++ ) userList.add( new User( "TEST", 10 + i, Sex.MALE ) );

        // 생성
        Stream<User> listStream = userList.stream();

        // 사용
        List<User> maleUsers = userList.stream()
                .filter( user -> user.sex == Sex.MALE )
                .toList();
        List<User> nextYearUpdatedUsers = userList.stream()
                .map( user -> {
                    user.onYearChange();
                    return user;
                } )
                .toList();

        Map<String,User> ageAscUsers = userList.stream()
                .sorted()
                .collect(Collectors.toMap(
                        User::getName,
                        Function.identity(),
                        ( o, n ) -> o
                ));


        String stringifiedUsersName = userList.stream()
                .map( v -> new StringBuilder( v.getName() ) )
                .reduce( ( a, b ) -> a.append(b) )
                .map( v -> v.toString() )
                .orElse( "ERROR" );
    }
}
