/**  gcsVMInfo_o.h  ***********************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Virtual Machine Information



            Cloud provider's virtual machine profile options.

*******************************************************************************/

#ifndef GCSVMInfo_API
#define GCSVMInfo_API


/*
      chicagovps.net price list 08.08.2019:
  Name           Type        CPU Speed  # Cores  RAM    Disk Space  Bandwidth  price   duraton
  Starter        kvm                             512MB  20GB        500GB       $2.50  month
  Standard       kvm                             1GB    30GB        1TB         $4.95  month
  Professional   kvm                             2GB    40GB        2TB         $9.95  month
  Enterprise     kvm                             3GB    50GB        3TB        $14.95  month
  Corporate      kvm                             4GB    60GB        4TB        $19.95  month
  Starter        OpenVZ VPS                      128MB  10GB        100GB       $1.25  month
  Standard       OpenVZ VPS                      512MB  20GB        500GB       $3.00  month
  Professional   OpenVZ VPS                      1GB    30GB        1TB         $4.00  month
  Enterprise     OpenVZ VPS                      2GB    60GB        2TB         $8.00  month
  Corporate      OpenVZ VPS                      4GB    80GB        3TB        $12.00  month
  Smart Server8  Dedicated   2.20GHz    2        8GB    100GB       10TB       $25.00  month
  Smart Server16 Dedicated   2.20GHz    4        16GB   200GB       10TB       $50.00  month
  Smart Server32 Dedicated   2.20GHz    8        32GB   400GB       10TB      $100.00  month
  Xeon E3-1240   Bare Metal  3.40GHz    4        16GB   1TB         10TB       $65.00  month
  Xeon E3-1240-2 Bare Metal  3.40GHz    4        16GB   2TB         10TB       $85.00  month
  Xeon E3-1240-3 Bare Metal  3.40GHz    8        32GB   2TB         10TB      $115.oo  month

      Some operating system choices:
  Linux Centos 5.8 X86 Min Gen2 V1
  Linux Centos 6.6 X86 64 Min Gen2 V1
  Linux Debian 7.0.0 X86 64 Min Gen2 V1
  Linux Debian 8.2 X86 64 Minimal Gen2 V1
  Linux Fedora 20 X86 64 Min Gen2 V1
  Linux Ubuntu 14.04 Server X86 Min Gen2 V1
  Linux Ubuntu 14.04 Server X86 64 Min New Gen2 V1
  Linux Ubuntu 16.04.3 Server Amd64 Gen2 V1



      Amazon aws ec2 abridged price list 08.08.2019:
  Name           Type        CPU Speed  # Cores  RAM    Disk Space  Bandwidth  price   duraton
  t2.nano        ec2                    1        512MB              Low
  t2.micro       ec2                    1        1GB                Low        free
  t2.small       ec2                    1        2GB                Low
  t2.medium      ec2                    2        4GB                Low
  t2.large       ec2                    2        8GB                Low
  t2.xlarge      ec2                    4        16GB               Moderate
  t2.2xlarge     ec2                    8        32GB               Moderate
  t3.nano        ec2                    2        512MB              UpTo 5Gb
  t3.micro       ec2                    2        1GB                UpTo 5Gb
  t3.small       ec2                    2        2GB                UpTo 5Gb
  t3.medium      ec2                    2        4GB                UpTo 5Gb
  t3.large       ec2                    2        8GB                UpTo 5Gb
  t3.xlarge      ec2                    4        16GB               UpTo 5Gb
  t3.2xlarge     ec2                    8        32GB               UpTo 5Gb
  m5ad.large     ec2                    2        8GB                UpTo 10Gb
  m5ad.xlarge    ec2                    4        16GB               UpTo 10Gb
  m5ad.2xlarge   ec2                    8        32GB               UpTo 10Gb
  m5ad.4xlaege   ec2                    16       64GB               UpTo 10Gb
  m5ad.12xlarge  ec2                    48       192GB              10Gb
  m5ad.24xlarge  ec2                    96       384GB              20Gb
  c5n.large      ec2                    2        5.25GB             UpTo 25Gb
  c5n.xlarge     ec2                    4        10.5GB             UpTo 25Gb
  c5n.2xlarge    ec2                    8        21GB               UpTo 25Gb
  c2n.4xlarge    ec2                    16       42GB               UpTo 25Gb
  c2n.9xlarge    ec2                    36       96GB               UpTo 50Gb
  c2n.16xlarge   ec2                    72       192GB              100Gb
  c5n.metal      ec2                    72       192GB              100Gb
  r5ad.large     ec2                    2        16GB               UpTo 10Gb
  r5ad.xlarge    ec2                    4        32GB               UpTo 10Gb
  r5ad.2xlarge   ec2                    8        64GB               UpTo 10Gb
  r5ad.4xlarge   ec2                    16       128GB              UpTo 10Gb
  r5ad.12xlarge  ec2                    48       364GB              10Gb
  r5ad.24xlarge  ec2                    96       768GB              20Gb

      Some operating system choices:
  Amazon Linux 2 AMI (HVM), x86-64
  Amazon Linux 2 AMI (HVM), Arm-64 
  Amazon Linux AMI 2018.03.0 (HVM), x86-64
  Red Hat Enterprise Linux 8 (HVM), x86-64
  Red Hat Enterprise Linux 8 (HVM), Arm-64
  SUSE Linux Enterprise Server 15 SP1 (HVM), x86-64
  SUSE Linux Enterprise Server 12 SP4 (HVM), x86-64
  Ubuntu Server 18.04 LTS (HVM), x86-64
  Ubuntu Server 18.04 LTS (HVM), Arm-64
  Ubuntu Server 14.04 LTS (HVM), x86-64

*/


#include "string_o"

#define GCSVMInfo_o             "gcsVMInfo_o"
#define GCSVMInfo_Index         "Index"
#define GCSVMInfo_CloudProvider "CloudProvider"
#define GCSVMInfo_Name          "Name"
#define GCSVMInfo_Type          "Type"
#define GCSVMInfo_CPUName       "CPUName"
#define GCSVMInfo_CPUGHz        "CPUGHz"
#define GCSVMInfo_CPUCores      "CPUCores"
#define GCSVMInfo_RAMMemory     "RAMMemory"
#define GCSVMInfo_SDDMemory     "SDDMemory"
#define GCSVMInfo_Bandwidth     "Bandwidth"
#define GCSVMInfo_Price         "Price"
#define GCSVMInfo_Duration      "Duration"
#define GCSVMInfo_OSShortName   "OSShortName"
#define GCSVMInfo_OSLongName    "OSLongName"


class gcsVMInfo_o  {
  protected:
    int                 Index;
    string_o            CloudProvider;
    string_o            Name;
    string_o            Type;
    string_o            CPUName;
    int                 CPUGHz;
    int                 CPUCores;
    int                 RAMMemory;
    int                 SDDMemory;
    int                 Bandwidth;
    int                 Price;
    int                 Duration;
    string_o            OSShortName;
    string_o            OSLongName;

  public:
    gcsVMInfo_o();
    gcsVMInfo_o(const gcsVMInfo_o&);
    virtual ~gcsVMInfo_o();
    gcsVMInfo_o&   operator = (const gcsVMInfo_o&);

    int             index() const;
    const string_o& cloudProvider() const;
    const string_o& name() const;
    const string_o& type() const;
    const string_o& cpuName() const;
    int             cpuGHz() const;
    int             cpuCores() const;
    int             ramMemory() const;
    int             sddMemory() const;
    int             bandwidth() const;
    int             price() const;
    int             duration() const;
    const string_o& osShortName() const;
    const char*     osLongName() const;

    void            setName(const string_o&);
    void            setBandwidth(const int);


    void            operator >> (string_o&) const;      // OLP representation.
    void            Serialize(string_o&) const;
    gcsVMInfo_o&    operator << (string_o&);      // Reconstruct.
    void            Deserialize(const string_o&);


};


/******************************************************************************/


inline const string_o& gcsVMInfo_o::name() const  {
    return  Name;
}

inline const string_o& gcsVMInfo_o::osShortName() const  {
    return  OSShortName;
}

inline const string_o& gcsVMInfo_o::cloudProvider() const  {
    return  CloudProvider;
}

inline int gcsVMInfo_o::index() const  {
    return  Index;
}

inline int gcsVMInfo_o::cpuCores() const  {
    return  CPUCores;
}

inline int gcsVMInfo_o::ramMemory() const  {
    return  RAMMemory;
}

inline int gcsVMInfo_o::bandwidth() const  {
    return  Bandwidth;
}

inline void gcsVMInfo_o::setBandwidth(const int bw)  {
    Bandwidth = bw;
}

inline void gcsVMInfo_o::setName(const string_o& n)  {
    Name = n;
}


#endif

/******************************************************************************/
