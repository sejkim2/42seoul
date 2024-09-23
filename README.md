# spring mvc 기본 기능

## @Controller
```
@Controller
public class MappingController {
    
    @RequestMapping("/sejkim2")
    public String helloBasic() {
        log.info("wow!!");
        return "test.html";
    }
}
```
* 반환 값이 String이면 뷰 이름으로 인식하여 뷰를 찾고 뷰가 랜더링
* 반환값은 뷰 파일 (템플릿)의 경로를 적어주면 되며 templates 디렉토리 하위의 파일들을 찾음

## @RestController
```
@RestController
public class MappingController {
    @RequestMapping("/sejkim2")
    public String helloBasic() {
        log.info("wow!!");
        return "ok";
    }
}
```
* @Controller와 다르게, 반환 값으로 뷰를 찾는 것이 아니라 http 메시지 바디로 직접 입력됨

## @RequestMapping("url")
> url이 들어오면 함수를 매핑
```
@RequestMapping("/sejkim2")
    public String helloBasic() {
        ...
    }
```
* @RequestMapping("url") -> url로 호출하면 아래 함수가 실행되도록 매핑해줌
* @RequestMapping(value = "url", method = http method (get, head, post, put ....) -> http method 지정하지 않으면 모두 허용됨

## Http method mapping 축약
* @GetMapping
* @PostMapping
* @PutMapping
* @DeleteMapping
* @PatchMapping
> 내부적으로 @RequestMapping(method = http method)를 지정하고 있음

## pathVariable (경로 변수) 사용
```
@GetMapping("/sejkim2/{hello_world}")
    public String mappingPath(@PathVariable("hello_world") String pathVariable) {
        log.info("pathVariable : {}", pathVariable);
        return "ok";
    }
```
* url에서 {} 안에 사용된 변수는 @@PathVariable(변수명)을 통해 가져올 수 있으며 다양한 타입으로 바인딩 가능하다

## http 요청 데이터 조회 - http request parameter
> 클라이언트에서 서버로 요청 데이터를 전달할 때 사용하는 방법 3가지
1. GET - 쿼리 파라미터
   * /url?username=hello&age=20
   * 메시지 바디 없이, url의 쿼리 파라미터에 데이터를 포함해서 전달
2. POST - HTML Form
    * 메시지 바디에 쿼리 파라미터 형식으로 전달됨 (GET에서의 쿼리 파라미터 방식과 동일)
3. POST, PUT, PATCH - HTTP message body
   * 메시지 바디에 직접 데이터를 저장하여 전달
    * HTTP API에서 사용
    * 데이터 타입은 보통 JSON

## servlet객체를 사용한 요청 파라미터 조회
```
@RequestMapping("/sejkim2")
    //반환형이 void 이고 response에 직접 데이터를 저장하므로 view 호출 x
    public void requestParam(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String username = request.getParameter("username");
        int age = Integer.parseInt(request.getParameter("age"));
        log.info("username ={}, age ={}", username, age);

        response.getWriter().write("ok");
    }
```
* servlet의 request, response 객체를 직접 사용하여 파싱하고 응답 메시지 작성하기
* servlet에 의존적인 코드

## @RequestParam
```
@ResponseBody
    @RequestMapping("/sejkim2")
    public String requestParam(@RequestParam("username") String memberName,
                               @RequestParam("age") int memberAge) {
        log.info("username={}, age={}", memberName, memberAge);
        return "ok";
    }
```
* @RequestParam : 파라미터 이름으로 바인딩
* @ResponseBody : View 조회를 무시하고, http message body에 직접 내용을 입력

## @RequesetParam Map
```
@ResponseBody
    @RequestMapping("/sejkim2")
    public String requestParamMap(@RequestParam Map<String, Object> paramMap) {
        log.info("username={}, age={}", paramMap.get("username"), paramMap.get("age"));
        return "ok";
    }
```
* 파라미터가 여러개이면 Map으로 사용 가능하다. ( Map<String, Object>)

## 요청 파라미터로부터 객체를 생성하는 방법 - 1. 직접 생성
> @RequestParam으로 직접 가져와서 객체를 생성하는 방식
```
    @Data
    class HelloData {
        private String username;
        private int age;
    }

    @ResponseBody
    @RequestMapping("/sejkim2")
    public String modelAttributeTest(@RequestParam("username") String username,
                                     @RequestParam("age") int age) {
        HelloData data = new HelloData();  //요청 파라미터로부터 받은 정보로 객체 생성
        data.setUsername(username);
        data.setAge(age);
        log.info("data.username={}, data.age={}", data.getUsername(), data.getAge());
        return "ok";
    }
```

## 2. ModelAttribute 사용
```
    @Data
    class HelloData {
        private String username;
        private int age;
    }

    @ResponseBody
    @RequestMapping("/sejkim2")
    public String modelAttributeTest(@ModelAttribute("data") HelloData data) {
        log.info("data.username={}, data.age={}", data.getUsername(), data.getAge());
        return "ok";
    }
```
* 스프링 mvc가 @ModelAttribute를 실행하는 흐름
  1. 객체를 생성
  2. 요청 파라미터의 이름으로 객체의 프로퍼티를 찾고, setter를 호출하여 바인딩 (key1=value1&key2=value2 에서 key1, key2가 객체의 프로퍼티와 다르면 바인딩 되지 않음)

