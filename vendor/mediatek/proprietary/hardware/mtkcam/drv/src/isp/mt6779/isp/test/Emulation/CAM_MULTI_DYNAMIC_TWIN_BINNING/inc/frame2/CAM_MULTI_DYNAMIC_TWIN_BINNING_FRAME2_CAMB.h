 //ptr->writeReg(0x1004, 0xe86879e8, CAM_B);              //CAM.CAM_B.DMA.CQ0I_BASE_ADDR
 //ptr->writeReg(0x1020, 0x52073a00, CAM_B);              //CAM.CAM_B.DMA.IMGO_BASE_ADDR
 //ptr->writeReg(0x1050, 0x511cf600, CAM_B);              //CAM.CAM_B.DMA.RRZO_BASE_ADDR
 //ptr->writeReg(0x1080, 0x51307000, CAM_B);              //CAM.CAM_B.DMA.AAO_BASE_ADDR
 //ptr->writeReg(0x10b0, 0x50610800, CAM_B);              //CAM.CAM_B.DMA.AFO_BASE_ADDR
 //ptr->writeReg(0x10e0, 0x57059a00, CAM_B);              //CAM.CAM_B.DMA.LCSO_BASE_ADDR
 //ptr->writeReg(0x1110, 0xa76140d0, CAM_B);              //CAM.CAM_B.DMA.UFEO_BASE_ADDR
 //ptr->writeReg(0x1140, 0x5089a400, CAM_B);              //CAM.CAM_B.DMA.PDO_BASE_ADDR
 //ptr->writeReg(0x1170, 0x52cbc000, CAM_B);              //CAM.CAM_B.DMA.BPCI_BASE_ADDR
 //ptr->writeReg(0x11a0, 0x9023f9a6, CAM_B);              //CAM.CAM_B.DMA.CACI_BASE_ADDR
 //ptr->writeReg(0x11d0, 0x55732000, CAM_B);              //CAM.CAM_B.DMA.LSCI_BASE_ADDR
 //ptr->writeReg(0x1200, 0x77753fb8, CAM_B);              //CAM.CAM_B.DMA.LSC3I_BASE_ADDR
 //ptr->writeReg(0x1230, 0x5648a400, CAM_B);              //CAM.CAM_B.DMA.PDI_BASE_ADDR
 //ptr->writeReg(0x1260, 0x54b62600, CAM_B);              //CAM.CAM_B.DMA.PSO_BASE_ADDR
 //ptr->writeReg(0x1290, 0x50dc0a00, CAM_B);              //CAM.CAM_B.DMA.LMVO_BASE_ADDR
 //ptr->writeReg(0x12c0, 0x56f31200, CAM_B);              //CAM.CAM_B.DMA.FLKO_BASE_ADDR
 //ptr->writeReg(0x12f0, 0x521dd600, CAM_B);              //CAM.CAM_B.DMA.RSSO_A_BASE_ADDR
 //ptr->writeReg(0x1320, 0xf86d949a, CAM_B);              //CAM.CAM_B.DMA.UFGO_BASE_ADDR
 //ptr->writeReg(0x1404, 0x572d1a00, CAM_B);              //CAM.CAM_B.DMA.IMGO_FH_BASE_ADDR
 //ptr->writeReg(0x1408, 0x5708ea00, CAM_B);              //CAM.CAM_B.DMA.RRZO_FH_BASE_ADDR
 //ptr->writeReg(0x140c, 0x53edb000, CAM_B);              //CAM.CAM_B.DMA.AAO_FH_BASE_ADDR
 //ptr->writeReg(0x1410, 0x54d58e00, CAM_B);              //CAM.CAM_B.DMA.AFO_FH_BASE_ADDR
 //ptr->writeReg(0x1414, 0x55f98400, CAM_B);              //CAM.CAM_B.DMA.LCSO_FH_BASE_ADDR
 //ptr->writeReg(0x1418, 0xeab652b2, CAM_B);              //CAM.CAM_B.DMA.UFEO_FH_BASE_ADDR
 //ptr->writeReg(0x141c, 0x570b0800, CAM_B);              //CAM.CAM_B.DMA.PDO_FH_BASE_ADDR
 //ptr->writeReg(0x1420, 0x53e21e00, CAM_B);              //CAM.CAM_B.DMA.PSO_FH_BASE_ADDR
 //ptr->writeReg(0x1424, 0x5430d400, CAM_B);              //CAM.CAM_B.DMA.LMVO_FH_BASE_ADDR
 //ptr->writeReg(0x1428, 0x55f65600, CAM_B);              //CAM.CAM_B.DMA.FLKO_FH_BASE_ADDR
 //ptr->writeReg(0x142c, 0x51430a00, CAM_B);              //CAM.CAM_B.DMA.RSSO_A_FH_BASE_ADDR
 //ptr->writeReg(0x1430, 0x9d13904a, CAM_B);              //CAM.CAM_B.DMA.UFGO_FH_BASE_ADDR
 ptr->writeReg(0x0198, 0x52493cf8, CAM_B);              //CAM.CAM_B.CQ.THR0_BASEADDR
 ptr->writeReg(0x019c, 0x448, CAM_B);                   //CAM.CAM_B.CQ.THR0_DESC_SIZE
 ptr->writeReg(0x0194, 0x11, CAM_B);                    //CAM.CAM_B.CQ.THR0_CTL
 ptr->writeReg(0x118c, 0x80000020, CAM_B);              //CAM.CAM_B.DMA.BPCI_CON
 ptr->writeReg(0x11ec, 0x80000020, CAM_B);              //CAM.CAM_B.DMA.LSCI_CON
 ptr->writeReg(0x0190, 0x100, CAM_B);                   //CAM.CAM_B.CQ.EN
 ptr->writeReg(0x1018, 0x29000000, CAM_B);              //CAM.CAM_B.DMA.SPECIAL_FUN_EN
 ptr->writeReg(0x0234, 0x1002, CAM_B);                  //CAM.CAM_B.TG.VF_CON (add from camsys_star_2.c)