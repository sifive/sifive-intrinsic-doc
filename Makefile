###############################################################################
# Utilities
###############################################################################
# Check that given variables are set and all have non-empty values,
# die with an error otherwise.
#
# Params:
# 1. Variable name(s) to test.
# 2. (optional) Error message to print.
check_defined = \
		$(strip $(foreach 1,$1, \
				$(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
		$(if $(value $1),, \
			$(error Undefined $1$(if $2, ($2))))

# Replace softfloat float-point types with LLVM compatible floating-point types
replace_float = \
		find $(1) -type f -exec sed -i 's/float16_t/_Float16/g' {} \;; \
		find $(1) -type f -exec sed -i 's/float32_t/float/g' {} \;; \
		find $(1) -type f -exec sed -i 's/float64_t/double/g' {} \;


###############################################################################
# Variables
###############################################################################
# Main output directory is default to auto-generated
OUTPUT_DIR := $(CURDIR)/auto-generated
###############################################################################
# Targets
###############################################################################
# In downstream we hold our own copy of golden becasue we will append more
# contents upon it. Comparing to rvv-intrinsic-internal/auto-generated, and not
# rvv-intrinsic-internal/auto-generated
GOLDEN_DIR = $(CURDIR)/auto-generated
TEST_DIR = $(CURDIR)/.tmp
diff-autogen:
	$(call check_defined, TEST_DIR, output directory for documents/tests generation)
	rm -rf ${abspath ${TEST_DIR}}
	$(MAKE) gen-all OUTPUT_DIR=${TEST_DIR}
	diff -qr ${TEST_DIR} ${GOLDEN_DIR}

gen-all: gen-document gen-test rif

gen-document:
	$(MAKE) -C rvv-intrinsic-doc/rvv-intrinsic-generator gen-document \
		OUTPUT_DIR=$(OUTPUT_DIR) \
		VENDOR_PATH=$(CURDIR)/sifive_specific \
		VENDOR_INST=$(CURDIR)/sifive_specific/vendor_inst.py \
		SKIP_DEFAULT_INST=ON
		SKIP_DEFAULT_INST=ON
	$(call replace_float, $(OUTPUT_DIR))

gen-test:
	$(MAKE) -C rvv-intrinsic-doc/rvv-intrinsic-generator gen-test \
		OUTPUT_DIR=$(OUTPUT_DIR) \
		VENDOR_PATH=$(CURDIR)/sifive_specific \
		VENDOR_INST=$(CURDIR)/sifive_specific/vendor_inst.py \
		SKIP_DEFAULT_INST=ON
	$(call replace_float, $(OUTPUT_DIR))

rif:
	$(MAKE) -C rvv-intrinsic-doc/rvv-intrinsic-generator vendor-generator \
		OUTPUT_DIR=$(OUTPUT_DIR) \
		VENDOR_INST=$(CURDIR)/sifive_specific/vendor_inst.py \
		VENDOR_GENERATOR_SCRIPT=$(CURDIR)/sifive_specific/vendor_generator.py \
		VENDOR_GENERATOR_NAME=RIFGenerator \
		VENDOR_GENERATOR_OUTPUT=rif.def \
		VENDOR_PATH=$(CURDIR)/sifive_specific
	$(call replace_float, $(OUTPUT_DIR))

yapf-format:
	yapf --in-place --recursive sifive_specific/*.py
	yapf --in-place --recursive sifive_specific/*/*.py

lint:
	pylint --rcfile rvv-intrinsic-doc/rvv-intrinsic-generator/.pylintrc \
		--recursive yes sifive_specific/*.py
	pylint --rcfile rvv-intrinsic-doc/rvv-intrinsic-generator/.pylintrc \
		--recursive yes sifive_specific/*/*.py
