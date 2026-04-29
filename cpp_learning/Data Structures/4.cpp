#include <iostream>
#include <vector>
#include <string>

class TV;
extern std::vector<TV> *allTVs;

class TV
{
private:
    int volume;
    int mode;
    int channel;
    int id;

    static int tvCount;
    static int dvdCount;

public:
    TV(int _id = 0, int _vol = 50, int _mode = 1, int _channel = 0)
        : volume(_vol), mode(_mode), channel(_channel), id(_id) {}

    ~TV() {}

    int getMode() const {
        return mode;
    }

    int getVolume() const {
        return volume;
    }

    int getChannel() const {
        return channel;
    }

    int getId() const {
        return id;
    }

    void setMode(int _mode) {
        mode = _mode;
    }

    void setChannel(int _channel) {
        channel = _channel;
    }

    void setVolume(int _volume) {
        volume = _volume;
    }

    void print() const {
        std::cout << "第" << id << "号电视机--";
        if (mode == 1)
            std::cout << "TV模式";
        else
            std::cout << "DVD模式";
        std::cout << "--频道" << channel << "--音量" << volume << std::endl;
    }

    static int getTVCount() {
        return tvCount;
    }

    static int getDVDCount() {
        return dvdCount;
    }

    static void setCounts() {
        int tvc = 0, dvdc = 0;
        if (allTVs != nullptr) {
            for (size_t i = 1; i < allTVs->size(); i++) {
                if ((*allTVs)[i].getMode() == 1)
                    tvc++;
                else
                    dvdc++;
            }
        }
        tvCount = tvc;
        dvdCount = dvdc;
    }

    friend void remoteControl(TV &tv, int newMode, int newChannel, int volumeChange);
};

int TV::tvCount = 0;
int TV::dvdCount = 0;
std::vector<TV> *allTVs = nullptr;

void remoteControl(TV &tv, int newMode, int newChannel, int volumeChange) {
    tv.setMode(newMode);

    if (newMode == 2) {
        tv.setChannel(99);
    } else {
        tv.setChannel(newChannel);
    }

    int newVolume = tv.getVolume() + volumeChange;
    if (newVolume < 0)
        newVolume = 0;
    else if (newVolume > 100)
        newVolume = 100;
    tv.setVolume(newVolume);

    TV::setCounts();

    tv.print();
}

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<TV> tvs;
    tvs.push_back(TV(0, 50, 1, 0));
    for (int i = 1; i <= n; i++) {
        tvs.push_back(TV(i, 50, 1, i));
    }

    allTVs = &tvs;

    for (int i = 0; i < t; i++) {
        int id, mode, channel, volumeChange;
        std::cin >> id >> mode >> channel >> volumeChange;

        remoteControl(tvs[id], mode, channel, volumeChange);
    }

    std::cout << "播放电视的电视机数量为" << TV::getTVCount() << std::endl;
    std::cout << "播放DVD的电视机数量为" << TV::getDVDCount() << std::endl;

    return 0;
}
