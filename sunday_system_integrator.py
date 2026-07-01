import time
import random
from datetime import datetime

class SystemArchitectureController:
    """Master Controller to validate E2E Integration of Gateway, DB, and Logging"""
    
    def __init__(self):
        print("⚡ [Master Control] Booting Up System Integration Test Suite...")
        self.system_healthy = True
        self.total_requests_processed = 0

    def trigger_api_gateway(self, user_ip):
        """Simulating Thursday's Token Bucket Traffic Shaper"""
        print(f"\n[Step 1] Gateway Ingesting Request from IP: {user_ip}")
        # Simulating a dynamic rate-limiting check
        available_tokens = random.choice([0, 5, 10]) 
        
        if available_tokens == 0:
            print("❌ [Gateway Alert] Rate Limit Exceeded! Status Code: 429 Too Many Requests.")
            self.log_to_central_engine("GATEWAY", "ERROR", f"Rate limit breached for IP {user_ip}")
            return False
        else:
            print(f"✅ [Gateway Pass] Token Available ({available_tokens}). Routing to Database Layer...")
            self.log_to_central_engine("GATEWAY", "INFO", f"Request authorized for IP {user_ip}")
            return True

    def execute_database_layer(self):
        """Simulating Friday's Relational Schema & SQL Inner Join"""
        print("[Step 2] Executing Relational Database Permission Matrix...")
        # Simulating data aggregation
        execution_status = random.choice(["SUCCESS", "INTEGRITY_ERROR"])
        
        if execution_status == "SUCCESS":
            print("✅ [DB Pass] SQL INNER JOIN Executed successfully. Verified Assigned Roles.")
            self.log_to_central_engine("DATABASE", "INFO", "User access matrix successfully verified.")
            return True
        else:
            print("❌ [DB Alert] Foreign Key Integrity Violation! Execution Blocked.")
            self.log_to_central_engine("DATABASE", "ERROR", "Integrity constraint failed on active transaction.")
            return False

    def log_to_central_engine(self, subsystem, level, message):
        """Simulating Saturday's Centralized Telemetry Pipeline"""
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
        print(f"   📢 [Telemetry Core] [{timestamp}] [{level}] [{subsystem}] {message}")

    def run_full_integration_diagnostics(self):
        """Running continuous live traffic simulations to test system resilience"""
        print("\n" + "="*80)
        print("🚀 STARTING FULL ARCHITECTURE INTEGRATION PIPELINE")
        print("="*80)
        
        test_ips = ["192.168.1.100", "10.0.0.45", "172.16.254.1"]
        
        for idx, ip in enumerate(test_ips, 1):
            print(f"\n--- Running Test Scenario #{idx} ---")
            self.total_requests_processed += 1
            
            # Step 1: Gateway Routing
            gateway_passed = self.trigger_api_gateway(ip)
            if not gateway_passed:
                self.system_healthy = False
                continue
                
            # Step 2: Database Authorization
            db_passed = self.execute_database_layer()
            if not db_passed:
                self.system_healthy = False
                continue
                
            print("🎉 [Success] End-to-End Request Pipeline Completed Without Failures.")
            time.sleep(0.5)

        # Final Report
        print("\n" + "="*80)
        print("📊 FINAL SYSTEM ARCHITECTURE HEALTH REPORT")
        print("="*80)
        print(f"Total Traffic Scenarios Simulated: {self.total_requests_processed}")
        if self.system_healthy:
            print("🟢 STATUS: ALL MICROSERVICES INTEGRATED SUCCESSFULLY [100% OPERATIONAL]")
        else:
            print("🔴 STATUS: DEGRADED PERFORMANCE [Review Incident Telemetry Logs Above]")
        print("="*80 + "\n")

if __name__ == "__main__":
    controller = SystemArchitectureController()
    controller.run_full_integration_diagnostics()