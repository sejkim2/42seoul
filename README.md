# Spring Validation

## Map<String, String> errors
> Model에 직접 넣어서 뷰 템플릿으로 전달하는 방식
> 타입 에러 발생 시 mvc 호출 전에 400 에러 발생하는 문제가 있음 (뷰 템플릿으로 에러 메시지 전달 불가능)
```
@PostMapping("/add")
    public String addItem(@ModelAttribute Item item, RedirectAttributes redirectAttributes, Model model) {

        Map<String, String> errors = new HashMap<>();

        if (!StringUtils.hasText(item.getItemName())) {
            errors.put("itemName", "상품 이름은 필수입니다.");
        }

        if (item.getPrice() == null || item.getPrice() < 1000 || item.getPrice() > 1000000) {
            errors.put("price", "가격은 1,000 ~ 1,000,000 까지 허용합니다.");
        }

        if (item.getQuantity() == null || item.getQuantity() >= 10000) {
            errors.put("quantity", "수량은 최대 9,999까지 허용합니다.");
        }

        if (item.getQuantity() != null && item.getQuantity() != null) {
            int resultPrice = item.getPrice() * item.getQuantity();
            if (resultPrice < 10000) {
                errors.put("globalError", "가격 * 수량의 합은  10,000 이상이어야 합니다. 현재 값 = " + resultPrice);
            }
        }

        if (!errors.isEmpty()) {
            model.addAttribute("errors", errors);
            return "validation/v1/addForm";
        }

        Item savedItem = itemRepository.save(item);
        redirectAttributes.addAttribute("itemId", savedItem.getId());
        redirectAttributes.addAttribute("status", true);
        return "redirect:/validation/v1/items/{itemId}";
    }
```

## bindingResult
> 스프링이 제공하는 오류 검증 보관 객체
> 타입 에러 발생 시 bindingResult에 오류 객체 (특정 필드에서 발생하기 때문에 필드 에러)를 저장하고 mvc 컨트롤러 정상 호출
> Model에 넣지 않아도 뷰 템플릿에서 bindingResult 접근 지원해줌
> 에러 발생 시 사용자가 입력했던 내용이 전부 사라지는 문제가 있음
```
public String addItemV2(@ModelAttribute Item item, BindingResult bindingResult, RedirectAttributes redirectAttributes) {
  '''
  bindingResult.addError(new FieldError("item", "itemName", "상품 이름은 필수입니다."));
  bindingResult.addError(new ObjectError("item", "가격 * 수량의 합은 10,000원 이상이어야 합니다. 현재 값 = " + resultPrice));
  '''
  if (bindingResult.hasErrors()) {
            log.info("errors={}", bindingResult);
            return "validation/v2/addForm";
        }
  '''
```
* bindingResult.addError()로 에러 객체 저장
* 검증 대상 객체(target) 바로 뒤에 선언되어야 함
* 필드 오류 : new FieldError(object, field, defaultmessage)
* 글로벌 오류 : new ObjectError(object, defaultmessage) -> 특정 필드에서 발생한 오류가 아니므로 필드 정보 인자 필요 없음
  
