지뢰찾기 게임 (Minesweeper Game)
📅 기간: 2025.03

📌 설명

C언어로 개발한 지뢰찾기 게임으로, 16x16 크기의 격자판에서 지뢰를 피하면서 안전한 칸을 열어야 하는 게임입니다.

사용자는 좌표를 입력하여 게임을 진행하며, 지뢰가 있는 칸을 밟으면 게임이 종료되고, 모든 안전한 칸을 열면 게임을 클리어하게 됩니다.

🛠 사용 기술 및 스택

Backend: C언어

Database: 없음

Tools: Visual Studio Code, GitHub
✨ 주요 기능

✅ 16x16 크기의 게임판에서 지뢰 4개 랜덤 배치

✅ 사용자가 선택한 좌표에 따라 지뢰가 있는지 확인하고 주변 숫자 표시

✅ 0인 칸은 자동으로 연결된 빈 칸을 열어주는 기능

✅ 지뢰를 밟으면 게임 종료

✅ 모든 안전한 칸을 열면 게임 클리어

✅ 게임 진행 중 학생이 선택한 칸에 대한 정보 출력

🛠 구현 상세

프로그램 구조 설계: 게임판을 2차원 배열로 관리하고, 지뢰를 랜덤으로 배치한 후, 각 칸의 주변 지뢰 개수를 계산하여 표시

기능 구현: 사용자가 선택한 좌표에 따라 지뢰를 밟았는지, 안전한 칸을 열었는지 판단

데이터 저장 방식: 2차원 배열을 활용하여 게임판 데이터를 관리

게임 종료/클리어 조건: 지뢰를 밟으면 게임 종료, 모든 안전한 칸을 열면 게임 클리어

유효성 검사: 입력받은 좌표가 올바른지, 이미 열린 칸인지 등의 검증 로직 적용

🚀 앞으로의 계획

그래픽 인터페이스를 통한 게임 화면 구현 (SDL 또는 OpenGL 활용)

사용자에게 더 나은 경험을 제공하기 위한 음성, 애니메이션 추가

고급 난이도 추가 및 지뢰 개수 증가, 게임 시간 제한 등의 기능 추가
