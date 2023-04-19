# born2beroot

## 운영체제란?  
>컴퓨터의 자원들을 효율적으로 관리하고, 사용자가 컴퓨터를 효과적으로 사용(생산성이 올라감)하기 위한 환경을 제공하는 프로그램이다. 즉, 컴퓨터와 사용자 간 인터페이스라고 보면 된다. 운영체제가 있기 때문에 사용자는 하드웨어
## 운영체제가 제공하는 기능 : 이러한 공통적인 역할을 운영체제가 수행해줌  
* 자원(프로세스) 관리 및 보호, 스케줄링 ** 여기서 자원이란, cpu 시간, 메모리, 네트워크 대역폭, 저장소 등을 포함한다.
* 컴퓨터와 사용자 간 인터페이스 제공
* 네트워크 관리
* 시스템 오류 검사 및 복구
* 입출력 기능 제공  
## 운영체제를 사용하는 이유  
> 처리능력 향상, 반환시간 단축, 사용 가능도 향상, 신뢰도 향상 등이 있다. 또한 이 네가지 지표는 운영체제 성능 평가의 기준이 된다.  
* 처리능력(Throughput) : 일정 시간 내 시스템이 처리하는 일의 양
* 반환시간(Turn Around Time) : 시스템이 작업을 요구받은 작업을 완료하는데 걸린 시간 (완료 시간 - 의뢰 시간)
* 사용가능도(Availability) : 시스템을 즉시 사용할 수 있는 용량의 양
* 신뢰도(Reaiabilty) : 시스템이 작업을 정확하게 해결하는 정도
## 가상머신이란?  
>가상머신이란? : https://www.vmware.com/kr/topics/glossary/content/virtual-machine.html  
>VM(Virtual Machine)이라고 불리며, 컴퓨터 환경이 하나의 호스트라면, 그 안에 있는 여러 게스트 중 하나이며, 호스트가 가지는 물리적 컴퓨터의 성격과 동일한 기능을 제공하는 소프트웨어 컴퓨터이다. 에뮬레이터와 비슷하다고 볼 수 있는데, 호스트가 에뮬레이터를 물리적으로 다른 장치라고 (실제로는 소프트웨어 장치지만) 믿는 것처럼 가상 머신 또한 호스트가 게스트를 물리적 컴퓨터라고 믿게 된다. 가상 머신은 시스템 가상 머신과 프로세스 가상 머신으로 나눌 수 있는데, 각각은 완전한 운영체제 혹은 단일 프로그램(프로세스)를 제공한다.  
## 하이퍼바이저란?  
>VMM(Virtual Machine Monitor)라고 불리며, 가상 머신을 생성 및 구동하는데 사용되는 소프트웨어이다. 
