
class MOTOR{
    public:
        void move(int power[4]);
        void cal(int dir,int speed);
        void stop();
        int m_speed[4];
    private:
        const int Address[4]={0x08,0x10,0x12,0x14};  //アドレス
        const float m_correction[4]={100,100,100,100};  //補正　速すぎる場合小さく，逆転する場合マイナスに
        const int m_dir[4]={-45,45,135,-135};  //モーターの取り付け角度　　-45:左前，45:右前，135:右後，-135:左後
};