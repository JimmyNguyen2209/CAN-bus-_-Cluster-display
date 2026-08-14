import cv2
from ultralytics import YOLO
from picamera2 import Picamera2

# 1. T?i "b? n�o" AI
model = YOLO('best.pt')

# 2. Kh?i t?o Camera
picam2 = Picamera2()
# �� s?a l?i d�ng chu?n c� ph�p (b? d?u ngo?c nh?n b?c ngo�i ch? main)
config = picam2.create_video_configuration(main={"size": (640, 480)})
picam2.configure(config)
picam2.start()

print("�� b?t M?t th?n b?ng Picamera2. B?m 'q' tr�n b�n ph�m d? t?t.")

try:
    while True:
        # 3. L?y khung h�nh
        frame = picam2.capture_array()

        # 4. �?o m�u RGB sang BGR cho OpenCV hi?u
        frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)

        # 5. Qu�t AI
        results = model(frame, conf=0.5, verbose=False)
        annotated_frame = results[0].plot()

        # 6. Chi?u l�n m�n h�nh
        cv2.imshow("ADAS Traffic Sign Recognition", annotated_frame)

        # B?m ph�m q d? tho�t
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
except Exception as e:
    print(f"L?i r?i �ng oi: {e}")
finally:
    picam2.stop()
    cv2.destroyAllWindows()
