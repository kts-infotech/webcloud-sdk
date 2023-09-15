using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebCloudAPITest.LicenseMenu;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        public void InvokeRegisterLicenceUserAPI()
        {
            FormRegister form = new FormRegister(ObjMainForm);
            form.Show();
            
        }
        public void InvokeGetLicenceInfoAPI()
        {
            GetLicenseInfo form = new GetLicenseInfo(ObjMainForm);
            form.Show();
        }
        public void InvokeValidateLicenseAPI()
        {
            (new LicenceTestApp()).Show();
        }
    }
}
