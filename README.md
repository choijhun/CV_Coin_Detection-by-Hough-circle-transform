# CV_Coin-Detector
Hough circle tranform 기반 원형 객체 탐지
# Grayscale 변환
- 원 검출에서는 color보다 object의 경계와 형태 정보가 중요하기 때문에 Grayscale로 변환
- edge 기반 연산의 계산량 줄일수 있음
# Gaussian Blur
- 이미지 속의 noise, 불필요한 세부 edge 제거
- 동전의 원형 edge를 안정적으로 검출할 수 있도록 전처리
# Hough Circle transform
- 원의 경계에 있는 edge 픽셀들로 원의 중심에 투표하도록 함.
- 원의 경계서는 gradient 방향이 원의 중심을 향하는 방향 or 반대 방향와 일치함
- gradient 방향에 존재하는 후보만 탐색하여 연산량 줄임
- 
# input, result
<img width="350" height="294" alt="coins4" src="https://github.com/user-attachments/assets/f6730614-a924-4c22-8163-f6677f181432" />
<img width="350" height="294" alt="스크린샷 2026-10-07 142937" src="https://github.com/user-attachments/assets/1a00c2d3-5ebe-4911-83d9-686090c60960" />







