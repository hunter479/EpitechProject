import React from "react";
import { MDBContainer, MDBFooter } from "mdbreact";
import './Footer.css';

const FooterPage = () => {
  return (
    <MDBFooter color="#0277bd light-blue darken-3" className="font-small pt-4 mt-4 footerStyle">
      <div className="footer-copyright text-center py-3">
        <MDBContainer fluid>
          &copy; {new Date().getFullYear()} Copyright: <a href="http://www.tek4u.fr"> tek4u.fr </a>
        </MDBContainer>
      </div>
    </MDBFooter>
  );
}

export default FooterPage;