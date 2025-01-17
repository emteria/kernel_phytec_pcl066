/*
 * Copyright 2017 NXP
 */
/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef MXC_MIPI_CSI2_H_
#define MXC_MIPI_CSI2_H_

#include <media/v4l2-device.h>
#include <media/v4l2-ctrls.h>

#define MXC_MIPI_CSI2_DRIVER_NAME	"mxc-mipi-csi2"
#define MXC_MIPI_CSI2_SUBDEV_NAME	MXC_MIPI_CSI2_DRIVER_NAME
#define MXC_MIPI_CSI2_MAX_DEVS		2
#define MXC_MIPI_CSI2_MAX_LANES		4

#define MIPI_CSI2_OF_NODE_NAME	"csi"

#define MXC_MIPI_CSI2_VC0_PAD_SINK		0
#define MXC_MIPI_CSI2_VC1_PAD_SINK		1
#define MXC_MIPI_CSI2_VC2_PAD_SINK		2
#define MXC_MIPI_CSI2_VC3_PAD_SINK		3

#define MXC_MIPI_CSI2_VC0_PAD_SOURCE	4
#define MXC_MIPI_CSI2_VC1_PAD_SOURCE	5
#define MXC_MIPI_CSI2_VC2_PAD_SOURCE	6
#define MXC_MIPI_CSI2_VC3_PAD_SOURCE	7
#define MXC_MIPI_CSI2_VCX_PADS_NUM		8

/* Subsystem CSR */
#define CSI2SS_BASE_OFFSET					0x0

#define CSI2SS_PLM_CTRL						(CSI2SS_BASE_OFFSET + 0x0)
#define CSI2SS_PLM_CTRL_PL_CLK_RUN			0x80000000
#define CSI2SS_PLM_CTRL_VSYNC_OVERRIDE		0x200
#define CSI2SS_PLM_CTRL_HSYNC_OVERRIDE		0x400
#define CSI2SS_PLM_CTRL_VALID_OVERRIDE		0x800
#define CSI2SS_PLM_CTRL_POLARITY_MASK		0x1000
#define CSI2SS_PLM_CTRL_POLARITY_HIGH		0x1000
#define CSI2SS_PLM_CTRL_POLARITY_LOW		0x0
#define CSI2SS_PLM_CTRL_ENABLE_PL			1
#define CSI2SS_PLM_CTRL_ENABLE_PL_OFFSET	0
#define CSI2SS_PLM_CTRL_ENABLE_PL_MASK		1

#define CSI2SS_PHY_CTRL						(CSI2SS_BASE_OFFSET + 0x4)
#define CSI2SS_PHY_CTRL_PD					1
#define CSI2SS_PHY_CTRL_PD_OFFSET			22
#define CSI2SS_PHY_CTRL_PD_MASK				0x400000
#define CSI2SS_PHY_CTRL_RTERM_SEL			1
#define CSI2SS_PHY_CTRL_RTERM_SEL_OFFSET	21
#define CSI2SS_PHY_CTRL_RTERM_SEL_MASK		0x200000
#define CSI2SS_PHY_CTRL_RX_HS_SETTLE_OFFSET	4
#define CSI2SS_PHY_CTRL_RX_HS_SETTLE_MASK	0x3F0
#define CSI2SS_PHY_CTRL_CONT_CLK_MODE		1
#define CSI2SS_PHY_CTRL_CONT_CLK_MODE_OFFSET	3
#define CSI2SS_PHY_CTRL_CONT_CLK_MODE_MASK	0x8
#define CSI2SS_PHY_CTRL_DDRCLK_EN			1
#define CSI2SS_PHY_CTRL_DDRCLK_EN_OFFSET	2
#define CSI2SS_PHY_CTRL_DDRCLK_EN_MASK		0x4
#define CSI2SS_PHY_CTRL_AUTO_PD_EN			1
#define CSI2SS_PHY_CTRL_AUTO_PD_EN_OFFSET	1
#define CSI2SS_PHY_CTRL_AUTO_PD_EN_MASK		0x2
#define CSI2SS_PHY_CTRL_RX_ENABLE			1
#define CSI2SS_PHY_CTRL_RX_ENABLE_OFFSET	0
#define CSI2SS_PHY_CTRL_RX_ENABLE_MASK		0x1

#define CSI2SS_PHY_STATUS					(CSI2SS_BASE_OFFSET + 0x8)
#define CSI2SS_PHY_TEST_STATUS				(CSI2SS_BASE_OFFSET + 0x10)
#define CSI2SS_PHY_TEST_STATUS_D0			(CSI2SS_BASE_OFFSET + 0x14)
#define CSI2SS_PHY_TEST_STATUS_D1			(CSI2SS_BASE_OFFSET + 0x18)
#define CSI2SS_PHY_TEST_STATUS_D2			(CSI2SS_BASE_OFFSET + 0x1C)
#define CSI2SS_PHY_TEST_STATUS_D3			(CSI2SS_BASE_OFFSET + 0x20)

#define CSI2SS_VC_INTERLACED				(CSI2SS_BASE_OFFSET + 0x30)
#define CSI2SS_VC_INTERLACED_VC0			1
#define CSI2SS_VC_INTERLACED_VC1			2
#define CSI2SS_VC_INTERLACED_VC2			4
#define CSI2SS_VC_INTERLACED_VC3			8
#define CSI2SS_VC_INTERLACED_OFFSET			0
#define CSI2SS_VC_INTERLACED_MASK			0xF

#define CSI2SS_DATA_TYPE						(CSI2SS_BASE_OFFSET + 0x38)
#define CSI2SS_DATA_TYPE_LEGACY_YUV420_8BIT		(1 << 2)
#define CSI2SS_DATA_TYPE_YUV422_8BIT       		(1 << 6)
#define CSI2SS_DATA_TYPE_YUV422_10BIT      		(1 << 7)
#define CSI2SS_DATA_TYPE_RGB444					(1 << 8)
#define CSI2SS_DATA_TYPE_RGB555					(1 << 9)
#define CSI2SS_DATA_TYPE_RGB565					(1 << 10)
#define CSI2SS_DATA_TYPE_RGB666					(1 << 11)
#define CSI2SS_DATA_TYPE_RGB888					(1 << 12)
#define CSI2SS_DATA_TYPE_RAW6					(1 << 16)
#define CSI2SS_DATA_TYPE_RAW8					(1 << 18)
#define CSI2SS_DATA_TYPE_RAW10					(1 << 19)
#define CSI2SS_DATA_TYPE_RAW12					(1 << 20)
#define CSI2SS_DATA_TYPE_RAW14					(1 << 21)

#define CSI2SS_YUV420_1ST_LINE_DATA_TYPE		(CSI2SS_BASE_OFFSET + 0x40)
#define CSI2SS_YUV420_1ST_LINE_DATA_TYPE_ODD	0
#define CSI2SS_YUV420_1ST_LINE_DATA_TYPE_EVEN	1
#define CSI2SS_YUV420_1ST_LINE_DATA_TYPE_OFFSET	0
#define CSI2SS_YUV420_1ST_LINE_DATA_TYPE_MASK	1

#define CSI2SS_CTRL_CLK_RESET					(CSI2SS_BASE_OFFSET + 0x44)
#define CSI2SS_CTRL_CLK_RESET_EN				1
#define CSI2SS_CTRL_CLK_RESET_OFFSET			0
#define CSI2SS_CTRL_CLK_RESET_MASK				1
#define CSI2SS_CTRL_CLK_RESET_CLK_OFF			1
#define CSI2SS_CTRL_CLK_RESET_CLK_OFFSET		1
#define CSI2SS_CTRL_CLK_RESET_CLK_MASK			0x1

#define CSI2SS_STREAM_FENCE_CTRL				(CSI2SS_BASE_OFFSET + 0x48)
#define CSI2SS_STREAM_FENCE_VC0					1
#define CSI2SS_STREAM_FENCE_VC1					2
#define CSI2SS_STREAM_FENCE_VC2					4
#define CSI2SS_STREAM_FENCE_VC3					8
#define CSI2SS_STREAM_FENCE_CTRL_OFFSET			0
#define CSI2SS_STREAM_FENCE_CTRL_MASK			0xF

#define CSI2SS_STREAM_FENCE_STATUS				(CSI2SS_BASE_OFFSET + 0x4C)

/* CSI-2 controller CSR */
#define CSI2RX_BASE_OFFSET						(0x100)

#define CSI2RX_CFG_NUM_LANES					(CSI2RX_BASE_OFFSET + 0x0)
#define CSI2RX_CFG_NUM_LANES_OFFSET				0
#define CSI2RX_CFG_NUM_LANES_MASK				0x3

#define CSI2RX_CFG_DISABLE_DATA_LANES			(CSI2RX_BASE_OFFSET + 0x4)
#define CSI2RX_CFG_DISABLE_DATA_LANES_3			8
#define CSI2RX_CFG_DISABLE_DATA_LANES_2			4
#define CSI2RX_CFG_DISABLE_DATA_LANES_1			2
#define CSI2RX_CFG_DISABLE_DATA_LANES_0			1
#define CSI2RX_CFG_DISABLE_DATA_LANES_OFFSET	0
#define CSI2RX_CFG_DISABLE_DATA_LANES_MASK		0xF

#define CSI2RX_BIT_ERR								(CSI2RX_BASE_OFFSET + 0x8)

#define CSI2RX_IRQ_STATUS							(CSI2RX_BASE_OFFSET + 0xC)
#define CSI2RX_IRQ_STATUS_CRC_ERROR					0x1
#define CSI2RX_IRQ_STATUS_1BIT_CRC_ERROR			0x2
#define CSI2RX_IRQ_STATUS_2BIT_CRC_ERROR			0x4
#define CSI2RX_IRQ_STATUS_ULPS_CHANGE				0x8
#define CSI2RX_IRQ_STATUS_DPHY_ERRSOTHS				0x10
#define CSI2RX_IRQ_STATUS_DPHY_ERRSOTSYNC_HS		0x20
#define CSI2RX_IRQ_STATUS_DPHY_ERRESC				0x40
#define CSI2RX_IRQ_STATUS_DPHY_ERRSYNCESC			0x80
#define CSI2RX_IRQ_STATUS_DPHY_ERRCTRL				0x100

#define CSI2RX_IRQ_MASK								(CSI2RX_BASE_OFFSET + 0x10)
#define CSI2RX_IRQ_MASK_CRC_ERROR					0x1
#define CSI2RX_IRQ_MASK_1BIT_CRC_ERROR				0x2
#define CSI2RX_IRQ_MASK_2BIT_CRC_ERROR				0x4
#define CSI2RX_IRQ_MASK_ULPS_CHANGE					0x8
#define CSI2RX_IRQ_MASK_DPHY_ERRSOTHS				0x10
#define CSI2RX_IRQ_MASK_DPHY_ERRSOTSYNC_HS			0x20
#define CSI2RX_IRQ_MASK_DPHY_ERRESC					0x40
#define CSI2RX_IRQ_MASK_DPHY_ERRSYNCESC				0x80
#define CSI2RX_IRQ_MASK_DPHY_ERRCTRL				0x100

#define CSI2RX_ULPS_STATUS							(CSI2RX_BASE_OFFSET + 0x14)
#define CSI2RX_ULPS_STATUS_CLK_LANE_ULPS			0x1
#define CSI2RX_ULPS_STATUS_DAT_LANE0_ULPS			0x2
#define CSI2RX_ULPS_STATUS_DAT_LANE1_ULPS			0x4
#define CSI2RX_ULPS_STATUS_DAT_LANE2_ULPS			0x8
#define CSI2RX_ULPS_STATUS_DAT_LANE3_ULPS			0x10
#define CSI2RX_ULPS_STATUS_CLK_LANE_MARK			0x20
#define CSI2RX_ULPS_STATUS_DAT_LANE0_MARK			0x40
#define CSI2RX_ULPS_STATUS_DAT_LANE1_MARK			0x80
#define CSI2RX_ULPS_STATUS_DAT_LANE2_MARK			0x100
#define CSI2RX_ULPS_STATUS_DAT_LANE3_MARK			0x200

#define CSI2RX_PPI_ERRSOT_HS						(CSI2RX_BASE_OFFSET + 0x18)
#define CSI2RX_PPI_ERRSOT_HS_DAT_LANE0				0x1
#define CSI2RX_PPI_ERRSOT_HS_DAT_LANE1				0x2
#define CSI2RX_PPI_ERRSOT_HS_DAT_LANE2				0x4
#define CSI2RX_PPI_ERRSOT_HS_DAT_LANE3				0x8

#define CSI2RX_PPI_ERRSOTSYNC_HS					(CSI2RX_BASE_OFFSET + 0x1C)
#define CSI2RX_PPI_ERRSOTSYNC_HS_DAT_LANE0			0x1
#define CSI2RX_PPI_ERRSOTSYNC_HS_DAT_LANE1			0x2
#define CSI2RX_PPI_ERRSOTSYNC_HS_DAT_LANE2			0x4
#define CSI2RX_PPI_ERRSOTSYNC_HS_DAT_LANE3			0x8

#define CSI2RX_PPI_ERRESC				   		 	(CSI2RX_BASE_OFFSET + 0x20)
#define CSI2RX_PPI_ERRESC_DAT_LANE0		   		 	0x1
#define CSI2RX_PPI_ERRESC_DAT_LANE1		   		 	0x2
#define CSI2RX_PPI_ERRESC_DAT_LANE2		   		 	0x4
#define CSI2RX_PPI_ERRESC_DAT_LANE3		   		 	0x8

#define CSI2RX_PPI_ERRSYNCESC			   		 	(CSI2RX_BASE_OFFSET + 0x24)
#define CSI2RX_PPI_ERRSYNCESC_DAT_LANE0	   		 	0x1
#define CSI2RX_PPI_ERRSYNCESC_DAT_LANE1	   		 	0x2
#define CSI2RX_PPI_ERRSYNCESC_DAT_LANE2	   		 	0x4
#define CSI2RX_PPI_ERRSYNCESC_DAT_LANE3	   		 	0x8

#define CSI2RX_PPI_ERRCONTROL			   		 	(CSI2RX_BASE_OFFSET + 0x28)
#define CSI2RX_PPI_ERRCONTROL_DAT_LANE0	   		 	0x1
#define CSI2RX_PPI_ERRCONTROL_DAT_LANE1	   		 	0x2
#define CSI2RX_PPI_ERRCONTROL_DAT_LANE2	   		 	0x4
#define CSI2RX_PPI_ERRCONTROL_DAT_LANE3	   		 	0x8

#define CSI2RX_CFG_DISABLE_PAYLOAD_0							(CSI2RX_BASE_OFFSET + 0x2C)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_LEGACY_YUV420_8BIT		(1 << 10)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_YUV422_8BIT				(1 << 14)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_YUV422_10BIT			(1 << 15)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RGB444					(1 << 16)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RGB555					(1 << 17)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RGB565					(1 << 18)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RGB666					(1 << 19)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RGB888					(1 << 20)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RAW6					(1 << 24)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RAW7					(1 << 25)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RAW8					(1 << 26)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RAW10					(1 << 27)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RAW12					(1 << 28)
#define CSI2RX_CFG_DISABLE_PAYLOAD_TYPE_RAW14					(1 << 29)

#define CSI2RX_CFG_DISABLE_PAYLOAD_1	(CSI2RX_BASE_OFFSET + 0x30)

struct csis_hw_reset {
	struct regmap *src;
	u8 req_src;
	u8 rst_val;
};
struct csis_phy_gpr {
	struct regmap *gpr;
	u8 req_src;
};

struct mxc_mipi_csi2_dev {
	struct v4l2_device		v4l2_dev;
	struct v4l2_subdev		sd;
	struct v4l2_subdev		*sensor_sd;
	struct v4l2_ctrl_handler	ctrl_handler;

	struct media_pad pads[MXC_MIPI_CSI2_VCX_PADS_NUM];
	struct v4l2_mbus_framefmt format;

	void __iomem *csr_regs;
	void __iomem *base_regs;
	struct platform_device *pdev;
	u32 flags;
	int irq;

	struct clk *clk_apb;
	struct clk *clk_core;
	struct clk *clk_esc;
	struct clk *clk_pxl;

	struct csis_hw_reset		hw_reset;
	struct csis_phy_gpr		phy_gpr;

	struct v4l2_async_subdev	asd;
	struct v4l2_async_notifier	subdev_notifier;
	struct v4l2_async_subdev	*async_subdevs[2];

	struct mutex lock;

	int	 id;
	u32 hs_settle;
	u32 send_level;
	u32 num_lanes;
	u8 data_lanes[4];
	u8 vchannel;
	u8 running;

	struct {
		unsigned long		ecc_two_bit;
		unsigned long		ecc_one_bit;
		unsigned long		crc;
		unsigned long		send_level;
		unsigned long		fifo_wr_ovfl;

		unsigned long		irq_crc;
		unsigned long		irq_ecc_one;
		unsigned long		irq_ecc_two;

		unsigned long		hs;
		unsigned long		hs_sync;

		unsigned long		esc;
		unsigned long		esc_sync;

		unsigned long		ctrl;

		uint8_t			lane_hs;
		uint8_t			lane_hs_sync;
		uint8_t			lane_esc;
		uint8_t			lane_esc_sync;
		uint8_t			lane_ctrl;
	}	err;

	struct dentry			*debugfs;
};

enum mxc_mipi_csi2_pm_state {
	MXC_MIPI_CSI2_PM_POWERED	= 0x1,
	MXC_MIPI_CSI2_PM_SUSPENDED	= 0x2,
	MXC_MIPI_CSI2_RUNTIME_SUSPENDED	= 0x4,
};

#endif
