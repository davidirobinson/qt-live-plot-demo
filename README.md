# Qt Live Plot Demo

![qt-live-plot-demo](https://drive.google.com/uc?export=download&id=1WQwwrLjZ5_V_APxpjhTAem20A4u-0f2J)

## Usage

### Dependencies

Download [Qt Open Source](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)

```
chmod +x qt-unified-linux-x64-3.2.2-online.run
./qt-unified-linux-x64-3.2.2-online.run  # Wait an eternity
```

### Build

```
mkdir -p build && cd build
cmake .. && make -j<#-cores>
```

### Run

```
cd build
./qt-live-plot-demo
```
