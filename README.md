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

