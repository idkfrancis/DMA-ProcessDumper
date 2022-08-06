# DMA-ProcessDumper
Dumps entire memory of target process on the user-mode using DMA with MemProcFS over a PCIe FPGA device 

## Building

* Copy `leechcore.h`, `vmmdll.h` and `vmm.lib` from MemProcFS into the DMA-ProcessDumper directory
* Compile using Visual Studio
* Copy `leechcore.dll`, `vmm.dll` and `FTD3XX.dll` from MemProcFS into the DMA-ProcessDumper\x64 directory

## Usage
```
DMA-ProcessDumper.exe target.exe
```
<img src="https://github.com/FrancisLaTruelle/DMA-ProcessDumper/blob/main/img/img1.PNG?raw=true">

## Ressources
- https://github.com/ufrisk/MemProcFS
- https://github.com/ufrisk/pcileech
- https://github.com/mgoodings/ReClass.NET-PciLeechPlugin
