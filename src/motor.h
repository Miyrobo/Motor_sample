//MDに関する参考サイト
//https://os.mbed.com/users/inst/code/NewMD2/wiki/GMD

//0.3秒間通信がないとMDがタイムアウトするので問題がある場合はタイマー割込みを使うなどして対応する
//参考 : http://zattouka.net/GarageHouse/micon/Arduino/TIMERtoLED/TIMERtoLED.htm


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

class encoder{
    public:
        void Setpin(int,int);
        long value;
        bool state[2];
        void reset();
        void read();
    private:
        int pin[2];
};

